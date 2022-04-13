// model.c
/*
 * Copyright (C) 2017 GreenWaves Technologies
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD license.  See the LICENSE file for details.
 *
 */


#define __XSTR(__s) __STR(__s)
#define __STR(__s) #__s
/* PMSIS includes. */
#include "pmsis.h"

/* Autotiler includes. */
#include "model.h"
// modelLernels.h 是 GenTile 自动生成的文件之一，和神经网络有关
#include "modelKernels.h"
#include "gaplib/ImgIO.h"
#include "img_proc.h"
#include "bsp/buffer.h"
#include "bsp/ai_deck.h"
#include "bsp/camera/himax.h"


#define pmsis_exit(n) exit(n)

#ifndef STACK_SIZE
#define STACK_SIZE      1024
#endif

#if defined(USE_HYPER)
   AT_HYPERFLASH_FS_EXT_ADDR_TYPE model_L3_Flash = 0;
#elif defined(USE_SPI)
   AT_QSPIFLASH_FS_EXT_ADDR_TYPE model_L3_Flash = 0;
#endif

// Softmax always outputs Q15 short int even from 8 bit input
L2_MEM short int *ResOut;
//Image in is unsigned but the model is trained with -1:1 inputs
//The preprocessing to scale the image is done in the CNN AT graph
L2_MEM unsigned char *Img_In;

// AT_INPUT_WIDTH AT_INPUT_HEIGHT AT_INPUT_COLORS 均在 Makefile 中定义
#define AT_INPUT_SIZE (AT_INPUT_WIDTH*AT_INPUT_HEIGHT*AT_INPUT_COLORS)
#define AT_INPUT_SIZE_BYTES (AT_INPUT_SIZE*sizeof(char))
#define CLASS_NUM 3

////////////////////////////////////////////////////////////////
#define QVGA_MODE
#define COLOR_IMAGE
static struct pi_device camera;

PI_L2 unsigned char *buff;
static PI_L2 uint8_t value = 0xff;

#define BUFF_SIZE (AT_INPUT_WIDTH*AT_INPUT_HEIGHT)
#define NB_FRAMES -1

////////////////////////////////////////////////////////////////
//#define PRINT_IMAGE

char *ImageName = NULL;
short int rec_digit=-1;

//short int *class_num = NULL;

static void cluster()
{
  //printf("Running on cluster\n");
#ifdef PERF
  //printf("Start timer\n");
  //gap_cl_starttimer();
  //gap_cl_resethwtimer();
#endif
  modelCNN(Img_In, ResOut);
  //printf("Runner completed\n");

  //Checki Results
  rec_digit = 0;
  short int highest = ResOut[0];
  for(int i = 0; i < CLASS_NUM; i++) {
    printf("class %d: %d \n", i, ResOut[i]);
    if(ResOut[i] > highest) {
      highest = ResOut[i];
      rec_digit = i;
    }
  }
  printf("\n");
  if(rec_digit==0)printf("Recognized: part_ripe\n");
  if(rec_digit==1)printf("Recognized: ripe\n");
  if(rec_digit==2)printf("Recognized: unripe\n");
  value = rec_digit+1; // 这里+1是因为无人机接收默认为0，因此结果要避开0
  //printf("Recognized: %d\n", rec_digit);
}

static int open_camera(struct pi_device *device)
{
    printf("Opening Himax camera\n");
    struct pi_himax_conf cam_conf;
    pi_himax_conf_init(&cam_conf);

#if defined(QVGA_MODE)
    cam_conf.format = PI_CAMERA_QVGA;
#endif

    pi_open_from_conf(device, &cam_conf);
    if (pi_camera_open(device))
        return -1;

    // Rotate camera orientation
    pi_camera_control(&camera, PI_CAMERA_CMD_START, 0);
    uint8_t set_value = 3;
    uint8_t reg_value;

    pi_camera_reg_set(&camera, IMG_ORIENTATION, &set_value);
    pi_time_wait_us(1000000);
    pi_camera_reg_get(&camera, IMG_ORIENTATION, &reg_value);
    if (set_value!=reg_value)
    {
        printf("Failed to rotate camera image\n");
        return -1;
    }
    pi_camera_control(&camera, PI_CAMERA_CMD_STOP, 0);

    pi_camera_control(device, PI_CAMERA_CMD_AEG_INIT, 0);

    return 0;
}


int test_model(void)
{
    printf("Entering main controller\n");
    printf("Reading image\n");
    //Reading Image from Bridge
    /*------------------- Allocate Image Buffer ------------------------*/
    printf("Going to alloc the image buffer!\n");
    // Img_In 保存图像数据，为其分配图片字节数的资源
    Img_In = (unsigned char *) AT_L2_ALLOC(0, AT_INPUT_SIZE_BYTES);
    //class_num (short int *) AT_L2_ALLOC(0,sizeof(short int));
    if(Img_In==NULL) {
      printf("Image buffer alloc Error!\n");
      pmsis_exit(-1);
    } 
    // 打开摄像头
    if (open_camera(&camera))
    {
        printf("Failed to open camera\n");
        pmsis_exit(-1);
    }
    
    // 调试QVGA模式
    uint8_t set_value = 0;
    uint8_t reg_value = 0;

    #ifdef QVGA_MODE
    set_value=1;
    pi_camera_reg_set(&camera, QVGA_WIN_EN, &set_value);
    pi_camera_reg_get(&camera, QVGA_WIN_EN, &reg_value);
    printf("qvga window enabled %d\n",reg_value);
    #endif
    
    // 测试同步拍摄
    set_value=0;                                                                                                                                          
    pi_camera_reg_set(&camera, VSYNC_HSYNC_PIXEL_SHIFT_EN, &set_value);
    pi_camera_reg_get(&camera, VSYNC_HSYNC_PIXEL_SHIFT_EN, &reg_value);
    printf("vsync hsync pixel shift enabled %d\n",reg_value);
    
    // 分配拍摄缓存
    buff = (unsigned char *) AT_L2_ALLOC(0, BUFF_SIZE);
    if (buff == NULL){ return -1;}
    
    // 配置uart
    struct pi_uart_conf conf;
    struct pi_device device;
    pi_uart_conf_init(&conf);
    conf.baudrate_bps =115200;
    pi_open_from_conf(&device, &conf);
    printf("[UART] Open\n");
    if (pi_uart_open(&device))
    {
    	printf("[UART] open failed !\n");
    	pmsis_exit(-1);
    }

    pi_uart_open(&device);
    
    // 配置和打开cluster
    struct pi_device cluster_dev;
    struct pi_cluster_conf cl_conf;
    cl_conf.id = 0;
    pi_open_from_conf(&cluster_dev, (void *) &cl_conf);
    if (pi_cluster_open(&cluster_dev))
    {
        printf("Cluster open failed !\n");
        pmsis_exit(-4);
    }

    // 为识别结果分配空间
    ResOut = (short int *) AT_L2_ALLOC(0, CLASS_NUM * sizeof(short int));
    if (ResOut == NULL)
    {
        printf("Failed to allocate Memory for Result (%d bytes)\n", CLASS_NUM *sizeof(short int));
        pmsis_exit(-3);
    }

    

    printf("Constructor\n");
    // IMPORTANT - MUST BE CALLED AFTER THE CLUSTER IS SWITCHED ON!!!!
    // 构造CNN
    if (modelCNN_Construct())
    {
        printf("Graph constructor exited with an error\n");
        pmsis_exit(-5);
    }

    printf("Call cluster\n");
    struct pi_cluster_task task = {0};
    task.entry = cluster;
    task.arg = NULL;
    task.stack_size = (unsigned int) STACK_SIZE;
    task.slave_stack_size = (unsigned int) SLAVE_STACK_SIZE;
    int nb_frames = 0;
    while(1 && (NB_FRAMES == -1 || nb_frames < NB_FRAMES)) {
            //拍摄图片
           pi_camera_control(&camera, PI_CAMERA_CMD_START, 0);
            pi_camera_capture(&camera, buff, BUFF_SIZE);
            pi_camera_control(&camera, PI_CAMERA_CMD_STOP, 0);
            
            //转换彩色图片
        demosaicking(buff, Img_In, AT_INPUT_WIDTH, AT_INPUT_HEIGHT, 0);
            // cluster执行任务
            pi_cluster_send_task_to_cl(&cluster_dev, &task);
    	    // 写入uart
            pi_uart_write(&device, &value, 1);
            nb_frames++;
    }
    


    // 析构CNN
    modelCNN_Destruct();

    // 关闭摄像头
    pi_camera_control(&camera, PI_CAMERA_CMD_STOP, 0);
    pi_camera_close(&camera);

    // Close the cluster
    pi_cluster_close(&cluster_dev);

    AT_L2_FREE(0, Img_In, AT_INPUT_SIZE_BYTES);
    AT_L2_FREE(0, buff, BUFF_SIZE);
    AT_L2_FREE(0, ResOut, CLASS_NUM * sizeof(short int));
    
    printf("Ended\n");

    pmsis_exit(0);
    return 0;
}

int main()
{
    printf("\n\n\t *** NNTOOL model Example ***\n\n");
    return pmsis_kickoff((void *) test_model);
}


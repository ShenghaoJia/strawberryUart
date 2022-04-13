#include "modelKernels.h"
L1_CL_MEM AT_L1_POINTER model_L1_Memory;
L2_MEM AT_L2_POINTER model_L2_Memory;
AT_HYPERRAM_POINTER model_L3_Memory;
static AT_HYPERRAM_T HyperRam;
static AT_HYPERFLASH_FS_T HyperFlash;
void S1_Op_input_1_formatterBody(
		unsigned char * __restrict__ In,
		signed char * __restrict__ Out0,
		signed char * __restrict__ Out1,
		signed char * __restrict__ Out2)

{
	/* Shared L1: 46656 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaW_Evt1;
	AT_L2_EVENT DmaW_Evt2;
	AT_L2_EVENT DmaW_Evt3;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	AT_HYPERRAM_CL_EVENT UchanHR2;
	AT_HYPERRAM_CL_EVENT UchanHR3;
	KerNormRGB888_fps_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _P_Out0, _C_Out0;
	unsigned int _SPP_Out0, _SP_Out0, _SC_Out0;
	unsigned int _P_Out1, _C_Out1;
	unsigned int _SPP_Out1, _SP_Out1, _SC_Out1;
	unsigned int _P_Out2, _C_Out2;
	unsigned int _SPP_Out2, _SP_Out2, _SC_Out2;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 21]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 21 logical tiles, 21 physical tiles
			Total Size: 237168 [Tile0, 21:[972x12, 19:972x12, 972x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 21:[972x12, 19:972x12, 972x4], 1]
		Tile0: [0, 11664, 11664], Tile1: [11664, 11664, 11664], Tile2; [23328, 11664, 11664]
	Ker Arg: Out0, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 0
		KerArgItSpace: 21 logical tiles, 21 physical tiles
			Total Size: 79056 [Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		Tile0: [0, 3888, 3888], Tile1: [3888, 3888, 3888], Tile2; [7776, 3888, 3888]
	Ker Arg: Out1, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 0
		KerArgItSpace: 21 logical tiles, 21 physical tiles
			Total Size: 79056 [Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		Tile0: [0, 3888, 3888], Tile1: [3888, 3888, 3888], Tile2; [7776, 3888, 3888]
	Ker Arg: Out2, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 0
		KerArgItSpace: 21 logical tiles, 21 physical tiles
			Total Size: 79056 [Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 21:[324x12, 19:324x12, 324x4], 1]
		Tile0: [0, 3888, 3888], Tile1: [3888, 3888, 3888], Tile2; [7776, 3888, 3888]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->W = (unsigned short int) (324);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 11664, 0, &DmaR_Evt1);
	_N_In=0;
	_C_Out0=0; _SC_Out0=3888;
	_SPP_Out0=0; _SP_Out0=0;
	_C_Out1=0; _SC_Out1=3888;
	_SPP_Out1=0; _SP_Out1=0;
	_C_Out2=0; _SC_Out2=3888;
	_SPP_Out2=0; _SP_Out2=0;
	/*============================= End Read Tiles Prolog ===============================*/
	for (T0Ind=0; T0Ind<21; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
		int T0Ind_Last = (T0Ind==20), T0Ind_NextLast = ((T0Ind+1)==20);
		/*================================= Prepare Tiles ===================================*/
		_SN_In = 0;
		if (!(T0Ind_Last)) {
			_N_In = _N_In + (11664); _SN_In = ((T0Ind_NextLast)?3888:11664); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
		if (_SN_In) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+11664*((T0Ind_Total+1)%2)),
					_SN_In, 0, &DmaR_Evt1);
		}
		/*============================= End Read Tiles ======================================*/
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->In = (unsigned char *__restrict__) (model_L1_Memory+0+11664*((T0Ind_Total)%2));
		KerArg0->Out0 = (signed char *__restrict__) (model_L1_Memory+23328+3888*((T0Ind_Total)%2));
		KerArg0->Out1 = (signed char *__restrict__) (model_L1_Memory+31104+3888*((T0Ind_Total)%2));
		KerArg0->Out2 = (signed char *__restrict__) (model_L1_Memory+38880+3888*((T0Ind_Total)%2));
		KerArg0->H = (unsigned short int) (T0Ind_Last?4:12);
		AT_FORK(gap_ncore(), (void *) CNN_NormRGB888_offset_fps, (void *) KerArg0);
		__CALL(CNN_NormRGB888_offset_fps, KerArg0);
		/*================================= Write Tiles =====================================*/
		if (_SP_Out0) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out0 */
		if (_SPP_Out0) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA write Out0 */
		if (_SP_Out0) AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out0+_P_Out0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+35492+3888*((T0Ind_Total+-1)%2)),
					_SP_Out0, 1, &UchanHR1);
		AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+35492+3888*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+23328+3888*((T0Ind_Total)%2)),
				_SC_Out0, 1, &DmaW_Evt1);
		if (_SP_Out1) AT_L2_WAIT(0, &DmaW_Evt2); /* Wait previous DMA write Out1 */
		if (_SPP_Out1) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait previous uDMA write Out1 */
		if (_SP_Out1) AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out1+_P_Out1), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+27716+3888*((T0Ind_Total+-1)%2)),
					_SP_Out1, 1, &UchanHR2);
		AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+27716+3888*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+31104+3888*((T0Ind_Total)%2)),
				_SC_Out1, 1, &DmaW_Evt2);
		if (_SP_Out2) AT_L2_WAIT(0, &DmaW_Evt3); /* Wait previous DMA write Out2 */
		if (_SPP_Out2) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR3); /* Wait previous uDMA write Out2 */
		if (_SP_Out2) AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out2+_P_Out2), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+19940+3888*((T0Ind_Total+-1)%2)),
					_SP_Out2, 1, &UchanHR3);
		AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+19940+3888*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+38880+3888*((T0Ind_Total)%2)),
				_SC_Out2, 1, &DmaW_Evt3);
		/*============================= End Write Tiles =====================================*/
		/*================================= Update Arg Pipeline =============================*/
		_SPP_Out0 = _SP_Out0;
		_P_Out0 = _C_Out0;_SP_Out0 = _SC_Out0;
		_SPP_Out1 = _SP_Out1;
		_P_Out1 = _C_Out1;_SP_Out1 = _SC_Out1;
		_SPP_Out2 = _SP_Out2;
		_P_Out2 = _C_Out2;_SP_Out2 = _SC_Out2;
		/*============================= End Update Arg Pipeline =============================*/
		/*================================= Prepare Tiles ===================================*/
		_SC_Out0 = 0;
		if (!(T0Ind_Last)) {
			_C_Out0 = _C_Out0 + (3888); _SC_Out0 = ((T0Ind_NextLast)?1296:3888); 
		}
		_SC_Out1 = 0;
		if (!(T0Ind_Last)) {
			_C_Out1 = _C_Out1 + (3888); _SC_Out1 = ((T0Ind_NextLast)?1296:3888); 
		}
		_SC_Out2 = 0;
		if (!(T0Ind_Last)) {
			_C_Out2 = _C_Out2 + (3888); _SC_Out2 = ((T0Ind_NextLast)?1296:3888); 
		}
		/*============================= End Prepare Tiles ===================================*/
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out0 */
	if (_SPP_Out0) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA write Out0 */
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out0+_P_Out0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+35492+3888*((T0Ind_Total+-1)%2)), _SP_Out0, 1, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait current uDMA write Out0 */
	AT_L2_WAIT(0, &DmaW_Evt2); /* Wait previous DMA write Out1 */
	if (_SPP_Out1) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait previous uDMA write Out1 */
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out1+_P_Out1), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+27716+3888*((T0Ind_Total+-1)%2)), _SP_Out1, 1, &UchanHR2);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait current uDMA write Out1 */
	AT_L2_WAIT(0, &DmaW_Evt3); /* Wait previous DMA write Out2 */
	if (_SPP_Out2) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR3); /* Wait previous uDMA write Out2 */
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out2+_P_Out2), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+19940+3888*((T0Ind_Total+-1)%2)), _SP_Out2, 1, &UchanHR3);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR3); /* Wait current uDMA write Out2 */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 45780 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR2;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _P_Out, _C_Out;
	unsigned int _SPP_Out, _SP_Out, _SC_Out;
	unsigned int _LPP_Out, _LP_Out, _LC_Out;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _LN_In, _LNN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 32, Tiled: 2][Tile0 Dim: 60][D0 Dim: Init: 3, Tiled: 1]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -2, Max Pipe Depth: 0
		KerArgItSpace: 120 logical tiles, 120 physical tiles
			Total Size: 153600 [D1, [1 x 115200, 38400]][Tile0, 60:[80x1, 58:80x1, 80x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 115200, 38400]][Tile0, 60:[80x1, 58:80x1, 80x1], 1]
		Tile0: [0, 1920, 80], Tile1: [80, 1920, 80], Tile2; [160, 1920, 80]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 128 [D1, [1 x 96, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 96, 32]]
		Tile0: [0, 128, 128], Tile1: [0, 128, 128], Tile2; [0, 128, 128]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [1 x 24, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 24, 8]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 32 [D1, [1 x 24, 8]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 24, 8]]
		Tile0: [0, 32, 32], Tile1: [0, 32, 32], Tile2; [0, 32, 32]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 120 logical tiles, 2 physical tiles
			Total Size: 864 [D1, [1 x 648, 216]][D0, [0 x 648, 648]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 648, 216]][D0, [0 x 648, 648]]
		Tile0: [0, 648, 27], Tile1: [648, 216, 27], Tile2; [0, 648, 27]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 60 logical tiles, 60 physical tiles
			Total Size: 237168 [D0, [0 x 237168, 237168]][Tile0, 60:[324x5, 58:324x5, 324x5], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 60:[324x5, 58:324x5, 324x5], 1][D0, [0 x 237168, 237168]]
		Tile0: [0, 4860, 1620], Tile1: [1296, 4860, 1620], Tile2; [2592, 4860, 1620]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 120 logical tiles, 1 physical tiles
			Total Size: 2457600 [D1, [1 x 1843200, 614400]][Tile0, 60:[160x2, 58:160x2, 160x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 1843200, 614400]][Tile0, 60:[160x2, 58:160x2, 160x2], 4]
		Tile0: [0, 30720, 1280], Tile1: [0, 30720, 1280], Tile2; [0, 30720, 1280]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 60 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 60:[9x1, 58:9x1, 9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 60:[9x1, 58:9x1, 9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+15048);
	KerArg0->W = (unsigned short int) (160);
	KerArg0->H = (unsigned short int) (2);
	KerArg1->W = (unsigned short int) (324);
	KerArg1->UsedW = (unsigned short int) (321);
	KerArg1->H = (unsigned short int) (5);
	KerArg1->UsedH = (unsigned short int) (5);
	KerArg1->InFeatures = (unsigned short int) (3);
	KerArg1->TotalInFeatures = (unsigned short int) (3);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+15048);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+15048);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+15048);
	KerArg2->W = (unsigned short int) (160);
	KerArg2->H = (unsigned short int) (2);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+45768);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+15048);
	KerArg3->W = (unsigned short int) (160);
	KerArg3->UsedW = (unsigned short int) (160);
	KerArg3->H = (unsigned short int) (2);
	KerArg3->UsedH = (unsigned short int) (2);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+45768);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=1920; _LC_Out=80;
	_SPP_Out=0; _SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+9720), 128, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+9848), 32, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+9880), 32, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+9912+0), 648, 0, &DmaR_Evt4);
	_N_Filter=0;
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+19940+0), 4860, 79056, 1620, 0, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+1296), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+19940+4860), 4860, 79056, 1620, 0, &UchanHR1);
	AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+19940+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 4860, 0, &DmaR_Evt5);
	_NN_In=1296; _SN_In=4860;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+45768), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1);
		/*================================= Prepare Tiles ===================================*/
		_SN_Filter = 0;
		if (!(D1Ind_Last)) {
			_N_Filter = _N_Filter + (648); _SN_Filter = ((1)?216:648); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+9912+648*((D1Ind_Total+1)%2)),
					_SN_Filter, 0, &DmaR_Evt4);
		}
		/*============================= End Read Tiles ======================================*/
		for (T0Ind=0; T0Ind<60; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==59), T0Ind_NextLast = ((T0Ind+1)==59), T0Ind_NextNextLast = ((T0Ind+2)==59);
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->Feat = (unsigned short int) (D1Ind_Last?8:24);
			KerArg0->Bias = (void * __restrict__) (model_L1_Memory+9720+((D1Ind)*96));
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+45768))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			{ /* Single iteration on D0 */
				int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
				/*================================= Prepare Tiles ===================================*/
				_SNN_In = 0;
				if (!(T0Ind_Last)) {
					if (!(T0Ind_NextLast)) {
						_NN_In = _NN_In + (1296); _LNN_In = (1620); _SNN_In = (3*_LNN_In); 
					} else if (!(D1Ind_Last)) {
						_NN_In = _NN_In + (-76464); _LNN_In = (1620); _SNN_In = (3*_LNN_In); 
					}
				} else if (!((D1Ind_Last))) {
					_NN_In = _NN_In + (1296); _LNN_In = (1620); _SNN_In = (3*_LNN_In); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
				if (_SNN_In) {
					AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+19940+4860*((D0Ind_Total)%2)),
							_SNN_In, 79056, _LNN_In, 0, &UchanHR1);
				}
				AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
				if (_SN_In) {
					AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+19940+4860*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+4860*((D0Ind_Total+1)%2)),
							_SN_In, 0, &DmaR_Evt5);
				}
				/*============================= End Read Tiles ======================================*/
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+4860*((D0Ind_Total)%2));
				KerArg1->OutFeatures = (unsigned short int) (D1Ind_Last?8:24);
				KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+9912+648*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride2_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride2_SQ8, KerArg1);
				/*================================= Update Arg Pipeline =============================*/
				_SN_In = _SNN_In;_LN_In = _LNN_In;
				/*============================= End Update Arg Pipeline =============================*/
				D0Ind_Total++;
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg2->Feat = (unsigned short int) (D1Ind_Last?8:24);
			KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+9848+((D1Ind)*24));
			KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+9880+((D1Ind)*24));
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			KerArg3->Feat = (unsigned short int) (D1Ind_Last?8:24);
			KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+11208+1920*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
			if (_SPP_Out) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait previous uDMA write Out */
			if (_SP_Out) AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+29660+1920*((T0Ind_Total+-1)%2)),
						_SP_Out, 4800, _LP_Out, 1, &UchanHR2);
			AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+29660+1920*((T0Ind_Total)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+11208+1920*((T0Ind_Total)%2)),
					_SC_Out, 1, &DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SPP_Out = _SP_Out;_LPP_Out = _LP_Out;
			_P_Out = _C_Out;_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (80); _LC_Out = (80); _SC_Out = (((D1Ind_Last)?8:24)*_LC_Out); 
			} else if (!(D1Ind_Last)) {
				_C_Out = _C_Out + (115200)+(-4720); _LC_Out = (80); _SC_Out = (((1)?8:24)*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
		/*================================= Update Arg Pipeline =============================*/
		/*============================= End Update Arg Pipeline =============================*/
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
	if (_SPP_Out) AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait previous uDMA write Out */
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Out+_P_Out), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+29660+1920*((T0Ind_Total+-1)%2)), _SP_Out, 4800, _LP_Out, 1, &UchanHR2);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR2); /* Wait current uDMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 46412 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerConv_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;
	KerPool_SQ8_T S_KerArg3, *KerArg3 = &S_KerArg3;

	/* Iteration space related variables */
	int D1Ind, D1Ind_Total=0, D1Ind_Last, D1Ind_NextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	int D0Ind, D0Ind_Total=0, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _C_Out;
	unsigned int _SP_Out, _SC_Out;
	unsigned int _LP_Out, _LC_Out;
	unsigned int _N_Filter;
	unsigned int _SN_Filter;
	unsigned int _NN_In;
	unsigned int _SN_In, _SNN_In;
	unsigned int _LN_In, _LNN_In;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D1 Dim: Init: 64, Tiled: 2][Tile0 Dim: 29][D0 Dim: Init: 32, Tiled: 4]
	Ker Arg: Out, Tiled Space: Tile0
		Min Pipe Depth: -1, Max Pipe Depth: 0
		KerArgItSpace: 58 logical tiles, 58 physical tiles
			Total Size: 72384 [D1, [1 x 36192, 36192]][Tile0, 29:[39x1, 27:39x1, 39x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 36192, 36192]][Tile0, 29:[39x1, 27:39x1, 39x1], 1]
		Tile0: [0, 1248, 39], Tile1: [39, 1248, 39], Tile2; [78, 1248, 39]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 256 [D1, [1 x 128, 128]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 128, 128]]
		Tile0: [0, 256, 256], Tile1: [0, 256, 256], Tile2; [0, 256, 256]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [1 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 32, 32]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 2 logical tiles, 1 physical tiles
			Total Size: 64 [D1, [1 x 32, 32]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 32, 32]]
		Tile0: [0, 64, 64], Tile1: [0, 64, 64], Tile2; [0, 64, 64]
	Ker Arg: Filter, Tiled Space: D1
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 232 logical tiles, 2 physical tiles
			Total Size: 18432 [D1, [1 x 9216, 9216]][D0, [3 x 2304, 2304]]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 9216, 9216]][D0, [3 x 2304, 2304]]
		Tile0: [0, 9216, 288], Tile1: [9216, 9216, 288], Tile2; [0, 9216, 288]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 116 logical tiles, 116 physical tiles
			Total Size: 153600 [D0, [3 x 38400, 38400]][Tile0, 29:[80x4, 27:80x4, 80x4], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[80x4, 27:80x4, 80x4], 1][D0, [3 x 38400, 38400]]
		Tile0: [0, 2560, 320], Tile1: [38400, 2560, 320], Tile2; [76800, 2560, 320]
	Ker Arg: ConvOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 58 logical tiles, 1 physical tiles
			Total Size: 1158144 [D1, [1 x 579072, 579072]][Tile0, 29:[78x2, 27:78x2, 78x2], 4]
		KerArgItSpace (User Kernel Iter Order):
			[D1, [1 x 579072, 579072]][Tile0, 29:[78x2, 27:78x2, 78x2], 4]
		Tile0: [0, 19968, 624], Tile1: [0, 19968, 624], Tile2; [0, 19968, 624]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 29 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 29:[9x1, 27:9x1, 9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 29:[9x1, 27:9x1, 9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+26432);
	KerArg0->W = (unsigned short int) (78);
	KerArg0->H = (unsigned short int) (2);
	KerArg0->Feat = (unsigned short int) (32);
	KerArg1->W = (unsigned short int) (80);
	KerArg1->UsedW = (unsigned short int) (80);
	KerArg1->H = (unsigned short int) (4);
	KerArg1->UsedH = (unsigned short int) (4);
	KerArg1->InFeatures = (unsigned short int) (8);
	KerArg1->OutFeatures = (unsigned short int) (32);
	KerArg1->TotalInFeatures = (unsigned short int) (32);
	KerArg1->Out = (int * __restrict__) (model_L1_Memory+26432);
	KerArg1->Pad = (v4s) 0;
	KerArg2->In = (int *__restrict__) (model_L1_Memory+26432);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+26432);
	KerArg2->Feat = (unsigned short int) (32);
	KerArg2->W = (unsigned short int) (78);
	KerArg2->H = (unsigned short int) (2);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+46400);
	KerArg3->In = (signed char * __restrict__) (model_L1_Memory+26432);
	KerArg3->W = (unsigned short int) (78);
	KerArg3->UsedW = (unsigned short int) (78);
	KerArg3->H = (unsigned short int) (2);
	KerArg3->UsedH = (unsigned short int) (2);
	KerArg3->Feat = (unsigned short int) (32);
	KerArg3->Pad = (v4s) 0;
	KerArg3->PoolMax = (unsigned char) (1);
	KerArg3->DoScale = (unsigned char) (0);
	KerArg3->Infos = (signed char * __restrict__) (model_L1_Memory+46400);
	/*================================= Read Tiles Prolog ===============================*/
	_C_Out=0; _SC_Out=1248; _LC_Out=39;
	_SP_Out=0;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5120), 256, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5376), 64, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5440), 64, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5504+0), 9216, 0, &DmaR_Evt4);
	_N_Filter=0;
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92324+0), 2560, 4800, 320, 0, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
	AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+38400), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92324+2560), 2560, 4800, 320, 0, &UchanHR1);
	AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+92324+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 2560, 0, &DmaR_Evt5);
	_NN_In=38400; _SN_In=2560;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+46400), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	for (D1Ind=0; D1Ind<2; D1Ind++, D1Ind_Total++) { /* Iteration on D1 */
		int D1Ind_Last = (D1Ind==1), D1Ind_NextLast = ((D1Ind+1)==1);
		/*================================= Prepare Tiles ===================================*/
		_SN_Filter = 0;
		if (!(D1Ind_Last)) {
			_N_Filter = _N_Filter + (9216); _SN_Filter = (9216); 
		}
		/*============================= End Prepare Tiles ===================================*/
		/*================================= Read Tiles ======================================*/
		AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Filter */
		if (_SN_Filter) {
			AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Filter+_N_Filter), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+5504+9216*((D1Ind_Total+1)%2)),
					_SN_Filter, 0, &DmaR_Evt4);
		}
		/*============================= End Read Tiles ======================================*/
		for (T0Ind=0; T0Ind<29; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==28), T0Ind_NextLast = ((T0Ind+1)==28), T0Ind_NextNextLast = ((T0Ind+2)==28);
			/*====================== Call Kernel LOC_D0_PROLOG =========================*/
			KerArg0->Bias = (void * __restrict__) (model_L1_Memory+5120+((D1Ind)*128));
			KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+46400))[5]);
			AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
			__CALL(KerParSetBiasB32_SQ8, KerArg0);
			for (D0Ind=0; D0Ind<4; D0Ind++, D0Ind_Total++) { /* Iteration on D0 */
				int D0Ind_Last = (D0Ind==3), D0Ind_NextLast = ((D0Ind+1)==3), D0Ind_NextNextLast = ((D0Ind+2)==3);
				/*================================= Prepare Tiles ===================================*/
				_SNN_In = 0;
				if (!(D0Ind_Last)) {
					if (!(D0Ind_NextLast)) {
						_NN_In = _NN_In + (38400); _LNN_In = (320); _SNN_In = (8*_LNN_In); 
					} else if (!(T0Ind_Last)) {
						_NN_In = _NN_In + (160)+(-115200); _LNN_In = (320); _SNN_In = (8*_LNN_In); 
					} else if (!(D1Ind_Last)) {
						_NN_In = _NN_In + (-4480)+(-115200); _LNN_In = (320); _SNN_In = (8*_LNN_In); 
					}
				} else if (!(T0Ind_Last)) {
					_NN_In = _NN_In + (38400); _LNN_In = (320); _SNN_In = (8*_LNN_In); 
				} else if (!((D1Ind_Last))) {
					_NN_In = _NN_In + (38400); _LNN_In = (320); _SNN_In = (8*_LNN_In); 
				}
				/*============================= End Prepare Tiles ===================================*/
				/*================================= Read Tiles ======================================*/
				AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read In */
				if (_SNN_In) {
					AT_HYPERRAM_CL_COPY2D(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) In+_NN_In), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92324+2560*((D0Ind_Total)%2)),
							_SNN_In, 4800, _LNN_In, 0, &UchanHR1);
				}
				AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read In */
				if (_SN_In) {
					AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+92324+2560*((D0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+2560*((D0Ind_Total+1)%2)),
							_SN_In, 0, &DmaR_Evt5);
				}
				/*============================= End Read Tiles ======================================*/
				/*====================== Call Kernel LOC_D0 =========================*/
				KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+2560*((D0Ind_Total)%2));
				KerArg1->Filter = (signed char * __restrict__) (model_L1_Memory+5504+((D0Ind)*72)+9216*((D1Ind_Total)%2));
				AT_FORK(gap_ncore(), (void *) KerParConv3x3Stride1_SQ8, (void *) KerArg1);
				__CALL(KerParConv3x3Stride1_SQ8, KerArg1);
				/*================================= Update Arg Pipeline =============================*/
				_SN_In = _SNN_In;_LN_In = _LNN_In;
				/*============================= End Update Arg Pipeline =============================*/
			} /* End iteration on D0 */
			/*====================== Call Kernel LOC_D0_EPILOG =========================*/
			KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+5376+((D1Ind)*32));
			KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+5440+((D1Ind)*32));
			AT_FORK(gap_ncore(), (void *) KerParReductIO_CC_SQ8, (void *) KerArg2);
			__CALL(KerParReductIO_CC_SQ8, KerArg2);
			KerArg3->Out = (signed char * __restrict__) (model_L1_Memory+23936+1248*((T0Ind_Total)%2));
			AT_FORK(gap_ncore(), (void *) KerParPool2x2Stride2_ReLU_SQ8, (void *) KerArg3);
			__CALL(KerParPool2x2Stride2_ReLU_SQ8, KerArg3);
			/*================================= Write Tiles =====================================*/
			if (_SP_Out) AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
			AT_L2_COPY2D(0, ((AT_L2_EXT_ADDR_TYPE) Out+_C_Out), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+23936+1248*((T0Ind_Total)%2)),
					_SC_Out, 1131, _LC_Out, 1, &DmaW_Evt1);
			/*============================= End Write Tiles =====================================*/
			/*================================= Update Arg Pipeline =============================*/
			_SP_Out = _SC_Out;_LP_Out = _LC_Out;
			/*============================= End Update Arg Pipeline =============================*/
			/*================================= Prepare Tiles ===================================*/
			_SC_Out = 0;
			if (!(T0Ind_Last)) {
				_C_Out = _C_Out + (39); _LC_Out = (39); _SC_Out = (32*_LC_Out); 
			} else if (!(D1Ind_Last)) {
				_C_Out = _C_Out + (36192)+(-1092); _LC_Out = (39); _SC_Out = (32*_LC_Out); 
			}
			/*============================= End Prepare Tiles ===================================*/
		} /* End iteration on Tile0 */
		/*================================= Update Arg Pipeline =============================*/
		/*============================= End Update Arg Pipeline =============================*/
	} /* End iteration on D1 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait previous DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S4_Linear_3x29x39x64(
		signed char * __restrict__ In,
		signed char * __restrict__ Filter,
		int * __restrict__ Bias,
		signed char * __restrict__ Out,
		unsigned char * __restrict__ Scale,
		unsigned char * __restrict__ ScaleN,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 48768 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaR_Evt3;
	AT_L2_EVENT DmaR_Evt4;
	AT_L2_EVENT DmaR_Evt5;
	AT_L2_EVENT DmaR_Evt6;
	AT_L2_EVENT DmaW_Evt1;
	AT_HYPERRAM_CL_EVENT UchanHR1;
	KerSetBias_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;
	KerLinear_SQ8_T S_KerArg1, *KerArg1 = &S_KerArg1;
	KerConvLinReduct_SQ8_T S_KerArg2, *KerArg2 = &S_KerArg2;

	/* Iteration space related variables */
	int D0Ind, D0Ind_Last, D0Ind_NextLast, D0Ind_NextNextLast;
	int T0Ind, T0Ind_Total=0, T0Ind_Last, T0Ind_NextLast, T0Ind_NextNextLast;
	/* User kernel arguments related variables */
	unsigned int _N_In;
	unsigned int _SN_In;
	unsigned int _NN_Filter;
	unsigned int _SN_Filter, _SNN_Filter;
	unsigned int _LN_Filter, _LNN_Filter;
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[D0 Dim: Init: 3, Tiled: 1][Tile0 Dim: 12]
	Ker Arg: In, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 1
		KerArgItSpace: 12 logical tiles, 12 physical tiles
			Total Size: 72384 [Tile0, 12:[1x6089, 10:1x6089, 1x5405], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 12:[1x6089, 10:1x6089, 1x5405], 1]
		Tile0: [0, 6089, 6089], Tile1: [6089, 6089, 6089], Tile2; [12178, 6089, 6089]
	Ker Arg: Filter, Tiled Space: Tile0
		Min Pipe Depth: 0, Max Pipe Depth: 2
		KerArgItSpace: 12 logical tiles, 12 physical tiles
			Total Size: 217152 [D0, [0 x 217152, 217152]][Tile0, 12:[1x6089, 10:1x6089, 1x5405], 1]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 217152, 217152]][Tile0, 12:[1x6089, 10:1x6089, 1x5405], 1]
		Tile0: [0, 18267, 6089], Tile1: [18267, 18267, 6089], Tile2; [36534, 18267, 6089]
	Ker Arg: Bias, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 12 [D0, [0 x 12, 12]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 12, 12]]
		Tile0: [0, 12, 12], Tile1: [0, 12, 12], Tile2; [0, 12, 12]
	Ker Arg: LinOut, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 12 [D0, [0 x 12, 12]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 12, 12]]
		Tile0: [0, 12, 12], Tile1: [0, 12, 12], Tile2; [0, 12, 12]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Scale, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: ScaleN, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [D0, [0 x 3, 3]]
		KerArgItSpace (User Kernel Iter Order):
			[D0, [0 x 3, 3]]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 12 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 12:[1x1, 10:1x1, 1x1], 9]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 12:[1x1, 10:1x1, 1x1], 9]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->Out = (int * __restrict__) (model_L1_Memory+48732);
	KerArg0->W = (unsigned short int) (1);
	KerArg0->H = (unsigned short int) (1);
	KerArg0->Feat = (unsigned short int) (3);
	KerArg0->Bias = (void * __restrict__) (model_L1_Memory+48720);
	KerArg1->Out = (void * __restrict__) (model_L1_Memory+48732);
	KerArg1->OutDim = (unsigned short int) (3);
	KerArg1->Infos = (signed char *__restrict__) (model_L1_Memory+48756);
	KerArg2->In = (int *__restrict__) (model_L1_Memory+48732);
	KerArg2->Out = (void *__restrict__) (model_L1_Memory+48744);
	KerArg2->Feat = (unsigned short int) (3);
	KerArg2->W = (unsigned short int) (1);
	KerArg2->H = (unsigned short int) (1);
	KerArg2->Scale = (unsigned char *__restrict__) (model_L1_Memory+48748);
	KerArg2->ScaleN = (unsigned char *__restrict__) (model_L1_Memory+48752);
	KerArg2->Infos = (signed char *__restrict__) (model_L1_Memory+48756);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+0), 6089, 0, &DmaR_Evt1);
	_N_In=0;
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+0), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92328+0), 18267, 0, &UchanHR1);
	AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read Filter */
	AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+18267), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92328+18268), 18267, 0, &UchanHR1);
	AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+92328+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12184+0), 18267, 0, &DmaR_Evt2);
	_NN_Filter=18267; _SN_Filter=18267;
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Bias+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48720), 12, 0, &DmaR_Evt3);
	AT_L2_WAIT(0, &DmaR_Evt3); /* Wait previous DMA read Bias */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Scale+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48748), 3, 0, &DmaR_Evt4);
	AT_L2_WAIT(0, &DmaR_Evt4); /* Wait previous DMA read Scale */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) ScaleN+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48752), 3, 0, &DmaR_Evt5);
	AT_L2_WAIT(0, &DmaR_Evt5); /* Wait previous DMA read ScaleN */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48756), 9, 0, &DmaR_Evt6);
	AT_L2_WAIT(0, &DmaR_Evt6); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on D0 */
		int D0Ind_Last = 1, D0Ind_NextLast = 1, D0Ind_NextNextLast = 1;
		/*====================== Call Kernel LOC_LOOP_PROLOG =========================*/
		KerArg0->NormBias = (unsigned char) (((char *)(model_L1_Memory+48756))[5]);
		AT_FORK(gap_ncore(), (void *) KerParSetBiasB32_SQ8, (void *) KerArg0);
		__CALL(KerParSetBiasB32_SQ8, KerArg0);
		for (T0Ind=0; T0Ind<12; T0Ind++, T0Ind_Total++) { /* Iteration on Tile0 */
			int T0Ind_Last = (T0Ind==11), T0Ind_NextLast = ((T0Ind+1)==11), T0Ind_NextNextLast = ((T0Ind+2)==11);
			/*================================= Prepare Tiles ===================================*/
			_SN_In = 0;
			if (!(T0Ind_Last)) {
				_N_In = _N_In + (6089); _SN_In = ((T0Ind_NextLast)?5405:6089); 
			} else if (!(1)) {
				_N_In = _N_In + (-66979); _SN_In = (6089); 
			}
			_SNN_Filter = 0;
			if (!(T0Ind_Last)) {
				if (!(T0Ind_NextLast)) {
					_NN_Filter = _NN_Filter + (18267); _LNN_Filter = ((T0Ind_NextNextLast)?5405:6089); _SNN_Filter = (3*_LNN_Filter); 
				}
			}
			/*============================= End Prepare Tiles ===================================*/
			/*================================= Read Tiles ======================================*/
			AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
			if (_SN_In) {
				AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+_N_In), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0+6092*((T0Ind_Total+1)%2)),
						_SN_In, 0, &DmaR_Evt1);
			}
			AT_HYPERRAM_CL_WAIT(&HyperRam, &UchanHR1); /* Wait previous uDMA read Filter */
			if (_SNN_Filter) {
				AT_HYPERRAM_CL_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) Filter+_NN_Filter), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory+92328+18268*((T0Ind_Total)%2)),
						_SNN_Filter, 0, &UchanHR1);
			}
			AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Filter */
			if (_SN_Filter) {
				AT_L2_COPY(0, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L2_Memory+92328+18268*((T0Ind_Total+1)%2)), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12184+18268*((T0Ind_Total+1)%2)),
						_SN_Filter, 0, &DmaR_Evt2);
			}
			/*============================= End Read Tiles ======================================*/
			/*====================== Call Kernel LOC_LOOP =========================*/
			KerArg1->In = (signed char * __restrict__) (model_L1_Memory+0+6092*((T0Ind_Total)%2));
			KerArg1->Weights = (signed char * __restrict__) (model_L1_Memory+12184+18268*((T0Ind_Total)%2));
			KerArg1->InDim = (unsigned short int) (T0Ind_Last?5405:6089);
			KerArg1->TotalInDim = (unsigned short int) (T0Ind_Last?5405:6089);
			AT_FORK(gap_ncore(), (void *) KerParLinearLayer_SQ8, (void *) KerArg1);
			__CALL(KerParLinearLayer_SQ8, KerArg1);
			/*================================= Update Arg Pipeline =============================*/
			_SN_Filter = _SNN_Filter;_LN_Filter = _LNN_Filter;
			/*============================= End Update Arg Pipeline =============================*/
		} /* End iteration on Tile0 */
		/*====================== Call Kernel LOC_LOOP_EPILOG =========================*/
		AT_FORK(gap_ncore(), (void *) KerParReduct_CC_SQ8, (void *) KerArg2);
		__CALL(KerParReduct_CC_SQ8, KerArg2);
	} /* End iteration on D0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+48744), 3, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
void S5_SoftMax(
		signed char * __restrict__ In,
		short int * __restrict__ Out,
		signed char * __restrict__ Infos)

{
	/* Shared L1: 24 bytes, L2 buffer: 0 bytes */
	/* Local variables used by this kernel */
	AT_L2_EVENT DmaR_Evt1;
	AT_L2_EVENT DmaR_Evt2;
	AT_L2_EVENT DmaW_Evt1;
	KerSoftMax_SQ8_T S_KerArg0, *KerArg0 = &S_KerArg0;

	/* Iteration space related variables */
	int T0Ind, T0Ind_Last;
	/* User kernel arguments related variables */
	/*============================= Ker Arg Iter Spaces =========================================
	User Kernel Iteration Space:
		[Tile0 Dim: 1]
	Ker Arg: In, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 3 [Tile0, 1:[1x3], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x3], 1]
		Tile0: [0, 3, 3], Tile1: [0, 3, 3], Tile2; [0, 3, 3]
	Ker Arg: Out, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 6 [Tile0, 1:[1x3], 2]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[1x3], 2]
		Tile0: [0, 6, 6], Tile1: [0, 6, 6], Tile2; [0, 6, 6]
	Ker Arg: Infos, Tiled Space: Buffer
		Min Pipe Depth: 0, Max Pipe Depth: 0
		KerArgItSpace: 1 logical tiles, 1 physical tiles
			Total Size: 9 [Tile0, 1:[9x1], 1]
		KerArgItSpace (User Kernel Iter Order):
			[Tile0, 1:[9x1], 1]
		Tile0: [0, 9, 9], Tile1: [0, 9, 9], Tile2; [0, 9, 9]
	======================== End Ker Arg Iter Spaces =========================================*/
	/*=========================== Call Kernel, Invariant assignment =====================*/
	KerArg0->In = (signed char *__restrict__) (model_L1_Memory+0);
	KerArg0->N = (unsigned short int) (3);
	KerArg0->Out = (short int *__restrict__) (model_L1_Memory+4);
	KerArg0->Infos = (signed char *__restrict__) (model_L1_Memory+12);
	/*================================= Read Tiles Prolog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) In+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+0), 3, 0, &DmaR_Evt1);
	AT_L2_WAIT(0, &DmaR_Evt1); /* Wait previous DMA read In */
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Infos+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+12), 9, 0, &DmaR_Evt2);
	AT_L2_WAIT(0, &DmaR_Evt2); /* Wait previous DMA read Infos */
	/*============================= End Read Tiles Prolog ===============================*/
	{ /* Single iteration on Tile0 */
		int T0Ind_Last = 1;
		/*====================== Call Kernel LOC_LOOP =========================*/
		KerArg0->Norm = (unsigned short int) (((char *)(model_L1_Memory+12))[0]);
		AT_FORK(gap_ncore(), (void *) KerParSoftMax_SQ8, (void *) KerArg0);
		__CALL(KerParSoftMax_SQ8, KerArg0);
	} /* End iteration on Tile0 */
	/*================================ Write Tiles Epilog ===============================*/
	AT_L2_COPY(0, ((AT_L2_EXT_ADDR_TYPE) Out+0), ((AT_L2_INT_ADDR_TYPE) model_L1_Memory+4), 6, 1, &DmaW_Evt1);
	AT_L2_WAIT(0, &DmaW_Evt1); /* Wait DMA write Out */
	/*============================ End Write Tiles Epilog ===============================*/
}
int modelCNN_Construct()

{
	AT_HYPERFLASH_FS_FC_EVENT UchanHF1;
	AT_HYPERRAM_FC_EVENT UchanHR2;
	AT_HYPERRAM_CONF_T HyperRamConf;
	AT_HYPERFLASH_FS_CONF_T HyperFlashConf;
	int Error;
	AT_HYPERRAM_CONF_INIT(&HyperRamConf, AT_MEM_L3_HRAM, 0);
	AT_HYPERFLASH_FS_CONF_INIT(&HyperFlashConf, AT_MEM_L3_HFLASH, 0);
	AT_HYPERRAM_OPEN(&HyperRam, &HyperRamConf, &Error);
	if (Error) return 1;
	AT_HYPERFLASH_FS_OPEN(&HyperFlash, &HyperFlashConf, "model_L3_Flash_Const.dat", &Error);
	if (Error) return 1;
	model_L3_Memory = (AT_HYPERRAM_POINTER) AT_HYPERRAM_ALLOC(&HyperRam, 607920);
	if (model_L3_Memory == 0) return 2;
	model_L2_Memory = (AT_L2_POINTER) AT_L2_ALLOC(0, 128863);
	if (model_L2_Memory == 0) return 3;
	model_L1_Memory = (AT_L1_POINTER) AT_L1_ALLOC(0, 48768);
	if (model_L1_Memory == 0) return 4;
	/* Moving S4_Weights, size 217152 from HyperFlash at 0 to (size 217152) HyperRam at 0..217151 */
	{
		int Size = 217152, Base = 0;
		while (Size) {
			int Chunk = Min(Size, 1024);
			AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 0+Base), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 0), Chunk, 0, &UchanHF1);
			AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
			AT_HYPERRAM_FC_COPY(&HyperRam, ((AT_HYPERRAM_EXT_ADDR_TYPE) model_L3_Memory + 0+Base), ((AT_HYPERRAM_INT_ADDR_TYPE) model_L2_Memory + 0), Chunk, 1, &UchanHR2);
			AT_HYPERRAM_FC_WAIT(&HyperRam, &UchanHR2);
			Base += Chunk;
			Size -= Chunk;
		}
	}
	/* Moving S2_Infos, size 9 from HyperFlash at 237024 to (size 9) L2 at 19872..19880 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237024), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19872), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Weights, size 864 from HyperFlash at 235584 to (size 864) L2 at 18432..19295 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 235584), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 18432), 864, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Biases, size 128 from HyperFlash at 236704 to (size 128) L2 at 19552..19679 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236704), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19552), 128, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_scale, size 32 from HyperFlash at 236960 to (size 32) L2 at 19808..19839 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236960), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19808), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S2_Mul_shift, size 32 from HyperFlash at 236992 to (size 32) L2 at 19840..19871 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236992), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19840), 32, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Infos, size 9 from HyperFlash at 237036 to (size 9) L2 at 19884..19892 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237036), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19884), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Weights, size 18432 from HyperFlash at 217152 to (size 18432) L2 at 0..18431 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 217152), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 0), 18432, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Biases, size 256 from HyperFlash at 236448 to (size 256) L2 at 19296..19551 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236448), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19296), 256, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_scale, size 64 from HyperFlash at 236832 to (size 64) L2 at 19680..19743 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236832), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19680), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S3_Mul_shift, size 64 from HyperFlash at 236896 to (size 64) L2 at 19744..19807 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 236896), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19744), 64, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Infos, size 9 from HyperFlash at 237048 to (size 9) L2 at 19896..19904 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237048), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19896), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Biases, size 12 from HyperFlash at 237060 to (size 12) L2 at 19908..19919 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237060), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19908), 12, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_scale, size 3 from HyperFlash at 237084 to (size 3) L2 at 19932..19934 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237084), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19932), 3, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S4_Mul_shift, size 3 from HyperFlash at 237088 to (size 3) L2 at 19936..19938 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237088), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19936), 3, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	/* Moving S5_Infos, size 9 from HyperFlash at 237072 to (size 9) L2 at 19920..19928 */
	AT_HYPERFLASH_FS_FC_COPY(&HyperFlash, ((AT_HYPERFLASH_FS_EXT_ADDR_TYPE) model_L3_Flash + 237072), ((AT_HYPERFLASH_FS_INT_ADDR_TYPE) model_L2_Memory + 19920), 9, 0, &UchanHF1);
	AT_HYPERFLASH_FS_FC_WAIT(&HyperFlash, &UchanHF1);
	return 0;
}
int modelCNN_Destruct()

{
	AT_HYPERRAM_FREE(&HyperRam, model_L3_Memory, 607920);
	AT_L2_FREE(0, model_L2_Memory, 128863);
	AT_L1_FREE(0, model_L1_Memory, 48768);
	AT_HYPERRAM_CLOSE(&HyperRam);
	AT_HYPERFLASH_FS_CLOSE(&HyperFlash);
	return 0;
}
unsigned int AT_GraphPerf[5];
unsigned int AT_GraphOperInfosNames[5] = {
	355752,
	17356800,
	83748288,
	217152,
	3,
};
char *AT_GraphNodeNames[5] = {
	"S1_Op_input_1_formatterBody",
	"S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu",
	"S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu",
	"S4_Linear_3x29x39x64",
	"S5_SoftMax",
};
int modelCNN(
		unsigned char * __restrict__ Input_1,
		signed short * __restrict__ Output_1)

{
	AT_GraphPerf[0] = gap_cl_readhwtimer();
	S1_Op_input_1_formatterBody(
		((unsigned char * __restrict__) Input_1), /* In */
		((signed char * __restrict__) (model_L3_Memory+217152)), /* Out0 */
		((signed char * __restrict__) ((model_L3_Memory+217152) + 79056)), /* Out1 */
		((signed char * __restrict__) ((model_L3_Memory+217152) + 158112)) /* Out2 */
	);
	AT_GraphPerf[0] = gap_cl_readhwtimer() - AT_GraphPerf[0];
	AT_GraphPerf[1] = gap_cl_readhwtimer();
	S2_Conv2d_32x3x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L3_Memory+217152)), /* In */
		((signed char * __restrict__) (model_L2_Memory+18432)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19552)), /* Bias */
		((signed char * __restrict__) (model_L3_Memory+454320)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19808)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19840)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19872)) /* Infos */
	);
	AT_GraphPerf[1] = gap_cl_readhwtimer() - AT_GraphPerf[1];
	AT_GraphPerf[2] = gap_cl_readhwtimer();
	S3_Conv2d_64x32x3x3_MaxPool_2x2_Relu(
		((signed char * __restrict__) (model_L3_Memory+454320)), /* In */
		((signed char * __restrict__) (model_L2_Memory+0)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19296)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+19940)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19680)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19744)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19884)) /* Infos */
	);
	AT_GraphPerf[2] = gap_cl_readhwtimer() - AT_GraphPerf[2];
	AT_GraphPerf[3] = gap_cl_readhwtimer();
	S4_Linear_3x29x39x64(
		((signed char * __restrict__) (model_L2_Memory+19940)), /* In */
		((signed char * __restrict__) (model_L3_Memory+0)), /* Filter */
		((signed int * __restrict__) (model_L2_Memory+19908)), /* Bias */
		((signed char * __restrict__) (model_L2_Memory+92324)), /* Out */
		((unsigned char * __restrict__) (model_L2_Memory+19932)), /* Scale */
		((signed char * __restrict__) (model_L2_Memory+19936)), /* ScaleN */
		((signed char * __restrict__) (model_L2_Memory+19896)) /* Infos */
	);
	AT_GraphPerf[3] = gap_cl_readhwtimer() - AT_GraphPerf[3];
	AT_GraphPerf[4] = gap_cl_readhwtimer();
	S5_SoftMax(
		((signed char * __restrict__) (model_L2_Memory+92324)), /* In */
		((signed short * __restrict__) Output_1), /* Out */
		((signed char * __restrict__) (model_L2_Memory+19920)) /* Infos */
	);
	AT_GraphPerf[4] = gap_cl_readhwtimer() - AT_GraphPerf[4];
	return 0;
}

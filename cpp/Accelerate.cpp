/*
 *  Accelerate.cpp
 *  BronzeFormatOSX
 *
 *  Created by Mick Grierson on 12/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "Accelerate.h"

extern	void vDSP_vclr1(
					   float *  __vDSP_C,
					   Stride   __vDSP_K,
					   Length   __vDSP_N)

{

	for (unsigned long i=0; i<__vDSP_N; i+=__vDSP_K) {
		__vDSP_C[i]=0;

	}
}

extern	void vDSP_vflt161(
						 short * A,
						 Stride   __vDSP_I,
						 float *  __vDSP_C,
						 Stride   __vDSP_K,
						 Length   __vDSP_N)

{

	for (unsigned long i=0; i<__vDSP_N; i++) {
		__vDSP_C[i*__vDSP_K]=(float) A[i*__vDSP_I];
	}
}


extern void vDSP_vsdiv1 (
   float *__vDSP_A,
   Stride __vDSP_I,
   float *__vDSP_B,
   float *__vDSP_C,
   Stride __vDSP_K,
   Length __vDSP_N
   ) {

for (unsigned long i=0; i<__vDSP_N; i++) {
		__vDSP_C[i*__vDSP_K]=__vDSP_A[i*__vDSP_I]/(*__vDSP_B);
	}


}

extern	void vDSP_vramp1(
						float *       __vDSP_A,
						float *       __vDSP_B,
						float *       __vDSP_C,
						Stride   __vDSP_K,
						Length   __vDSP_N)

{
	float val = __vDSP_A[0];

	for (unsigned long i=0; i<__vDSP_N; i++) {

		__vDSP_C[i*__vDSP_K]=val;
		val+=*__vDSP_B;
	}
}

extern	void vDSP_vmul1(
					   const float   __vDSP_input1[],
					   Stride   __vDSP_stride1,
					   const float   __vDSP_input2[],
					   Stride   __vDSP_stride2,
					   float         __vDSP_result[],
					   Stride   __vDSP_strideResult,
					   Length   __vDSP_size)
{

	for (unsigned long i=0; i<__vDSP_size; i++) {

		__vDSP_result[i*__vDSP_strideResult]=__vDSP_input1[i*__vDSP_stride1]*__vDSP_input2[i*__vDSP_stride2];
	}
}

extern	void vDSP_vadd1(
					   const float   __vDSP_input1[],
					   Stride   __vDSP_stride1,
					   const float   __vDSP_input2[],
					   Stride   __vDSP_stride2,
					   float         __vDSP_result[],
					   Stride   __vDSP_strideResult,
					   Length   __vDSP_size)
{

	for (unsigned long i=0; i<__vDSP_size; i++) {

		__vDSP_result[i*__vDSP_strideResult]=__vDSP_input1[i*__vDSP_stride1]+__vDSP_input2[i*__vDSP_stride2];
	}


}

extern	void vDSP_vsma1(
					   const float *  __vDSP_A,
					   Stride    __vDSP_I,
					   const float *  __vDSP_B,
					   const float *  __vDSP_C,
					   Stride    __vDSP_K,
					   float *        __vDSP_D,
					   Stride    __vDSP_L,
					   Length    __vDSP_N)
{

	for (unsigned long i=0; i<__vDSP_N; i++) {

		__vDSP_D[i*__vDSP_L]=(__vDSP_A[i*__vDSP_I]*(*__vDSP_B))+__vDSP_C[i*__vDSP_K];
	}


}

extern	void vDSP_meanv1(
						float *       __vDSP_A,
						Stride   __vDSP_I,
						float *       __vDSP_C,
						Length   __vDSP_N)
{
	float sum=0;

	for (unsigned long i=0; i<__vDSP_N; i++) {

		sum+=__vDSP_A[i*__vDSP_I];
	}

	__vDSP_C[0]=sum/__vDSP_N;

}

extern void vDSP_vfill1(
					   float *       __vDSP_A,
					   float *       __vDSP_C,
					   Stride   __vDSP_K,
					   Length   __vDSP_N)
{

	for (unsigned long i=0; i<__vDSP_N; i++) {

		__vDSP_C[i*__vDSP_K]=__vDSP_A[0];
	}
}

extern void  vDSP_vsmul1(
						const float    __vDSP_input1[],
						Stride    __vDSP_stride1,
						const float *  __vDSP_input2,
						float          __vDSP_result[],
						Stride    __vDSP_strideResult,
						Length    __vDSP_size)
{

	for (unsigned long i=0; i<__vDSP_size; i++) {

		__vDSP_result[i*__vDSP_strideResult]=__vDSP_input1[i*__vDSP_stride1]*(*__vDSP_input2);
	}
}

extern void vDSP_vclip1(
					   float *       __vDSP_A,
					   Stride   __vDSP_I,
					   float *       __vDSP_B,
					   float *       __vDSP_C,
					   float *       __vDSP_D,
					   Stride   __vDSP_L,
					   Length   __vDSP_N)
{

	for (unsigned long i=0;i<__vDSP_N; i++) {

		if (__vDSP_A[i*__vDSP_I]<__vDSP_B[0]) {

			__vDSP_D[i*__vDSP_L]=__vDSP_B[0];
		}

		else if (__vDSP_A[i*__vDSP_I]>__vDSP_C[0]) {

			__vDSP_D[i*__vDSP_L]=__vDSP_C[0];

		}

		else {
			__vDSP_D[i*__vDSP_L]=__vDSP_A[i*__vDSP_I];

		}

	}
}


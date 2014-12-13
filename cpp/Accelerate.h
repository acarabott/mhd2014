/*
 *  Accelerate.h
 *  BronzeFormatOSX
 *
 *  Created by Mick Grierson on 12/04/2011.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _ACCELERATE
#define _ACCELERATE

typedef	unsigned long Length;

typedef long Stride;


extern	void vDSP_vclr(
			  float *       __vDSP_C,
			  Stride   __vDSP_K,
			  Length   __vDSP_N);

extern void vDSP_vsdiv(
   float *__vDSP_A,
   Stride __vDSP_I,
   float *__vDSP_B,
   float *__vDSP_C,
   Stride __vDSP_K,
   Length __vDSP_N
);

extern	void vDSP_vflt16(
				short *       A,
				Stride   __vDSP_I,
				float *       __vDSP_C,
				Stride   __vDSP_K,
				Length   __vDSP_N);

extern	void vDSP_vramp(
			   float *       __vDSP_A,
			   float *       __vDSP_B,
			   float *       __vDSP_C,
			   Stride   __vDSP_K,
						Length   __vDSP_N);

extern	void vDSP_vmul(
				   const float   __vDSP_input1[],
				   Stride   __vDSP_stride1,
				   const float   __vDSP_input2[],
				   Stride   __vDSP_stride2,
				   float         __vDSP_result[],
				   Stride   __vDSP_strideResult,
				   Length   __vDSP_size);

extern	void vDSP_vadd(
			  const float   __vDSP_input1[],
			  Stride   __vDSP_stride1,
			  const float   __vDSP_input2[],
			  Stride   __vDSP_stride2,
			  float         __vDSP_result[],
			  Stride   __vDSP_strideResult,
				   Length   __vDSP_size);

extern	void vDSP_vsma(
			  const float *  __vDSP_A,
			  Stride    __vDSP_I,
			  const float *  __vDSP_B,
			  const float *  __vDSP_C,
			  Stride    __vDSP_K,
			  float *        __vDSP_D,
			  Stride    __vDSP_L,
			Length    __vDSP_N);

extern	void vDSP_meanv(
			   float *       __vDSP_A,
			   Stride   __vDSP_I,
			   float *       __vDSP_C,
					Length   __vDSP_N);

extern void vDSP_vfill(
		   float *       __vDSP_A,
		   float *       __vDSP_C,
		   Stride   __vDSP_K,
					   Length   __vDSP_N);

extern void vDSP_vsmul(
		   const float    __vDSP_input1[],
		   Stride    __vDSP_stride1,
		   const float *  __vDSP_input2,
		   float          __vDSP_result[],
		   Stride    __vDSP_strideResult,
		   Length    __vDSP_size);

extern void vDSP_vclip(
		   float *       __vDSP_A,
		   Stride   __vDSP_I,
		   float *       __vDSP_B,
		   float *       __vDSP_C,
		   float *       __vDSP_D,
		   Stride   __vDSP_L,
		   Length   __vDSP_N);


#endif
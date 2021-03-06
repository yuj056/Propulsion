/* dev_R3grid.h
 * R3 under discretization (discretize functor) to a thread block
 * Ernest Yeung  ernestyalumni@gmail.com
 * 20160701
 */
#ifndef __DEV_R3GRID_H__
#define __DEV_R3GRID_H__

#include "../commonlib/errors.h"

extern __constant__ int dev_Ld[3]; // L^{d=3} = (L_x,L_y,L_z) \in \mathbb{N}^3

class dev_Grid3d
{
	public:
		dim3 Ld;
	
		float *dev_rho;
		float3 *dev_u;
		float *dev_E;

		// constructor
		__host__ dev_Grid3d( dim3 );

//		__host__ ~dev_Grid3d();

		__host__ int NFLAT();
};

class dev_block3d
{
	public:
		unsigned int  N_is[3];

		__device__ dev_block3d(unsigned int N_x, unsigned int N_y, unsigned int N_z);

		__device__ int flatten(int i_x, int i_y, int i_z);
};

#endif // __DEV_R3GRID_H__

 

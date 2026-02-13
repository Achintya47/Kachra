#include <stdio.h>

// __global__ tells the compiler that this code is supposed to 
// be run on the device (cuda) not the host (cpu)
__global__ void add(int a, int b, int *c) {
    *c = a + b;
}

int main(void) {
    int host_int;
    int* cuda_int;
    // Allocates an integer on the device, similar to C's malloc
    cudaMalloc((void**)&cuda_int, sizeof(int));
    
    add<<1, 1>>(2, 7, cuda_int);

    cudaMemcpy(&host_int, 
        cuda_int, sizeof(int), cudaMemcpyDeviceToHost);

    printf("%d", host_int);
    cudaFree(cuda_int);
}
#include <stdio.h>

__global__ void add(int* arr_1, int* arr2, int* destination_arr) {
    int tid = blockIdx.x;
    if (tid < N) 
        c[tid] = a[tid] + b[tid];
}

#define N 10
int main (
    int a[N], b[N], c[N];
    int *dev_a, *dev_b, *dev_c;

    cudaMalloc((void**)&dev_a, N * sizeof(int));
    cudaMalloc((void**)&dev_b, N * sizeof(int));
    cudaMalloc((void**)&dev_c, N * sizeof(int));

    // We're populating the arrays on the CPU, then will copy them
    // to the device. Populating on the device itself would've been much faster
    for (int i = 0; i < N; i++) {
        a[i] = -i;
        b[i] = i * i;
    }

    cudaMemcpy(dev_a, a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_b, b, N * sizeof(int), cudaMemcpyHostToDevice);

    add << N, 1 >>(dev_a, dev_b, dev_c);

    cudaMemcpy(c, dev_c, N * sizeof(int), cudaMemcpyDeviceToHost);
    
    cudaFree(dev_a);
    cudaFree(dev_b);
    cudaFree(dev_c);


)
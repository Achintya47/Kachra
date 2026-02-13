## 13-02-2026


### __global__ qualifier
__global__ void add(int a, int b, int *c) {
    *c = a + b;
}
Instructs the compiler that this code is to be run on the device, not the host.
nvcc gives the function kernel() to the compiler that handles device code, and feeds main() to the host compiler. What?


### DEVICE POINTERS (devPtr)
(By pointer here I mean, the device pointer returned by cudaMalloc())
-- You can pass pointers to functions that execute on the device
-- You can pass pointers to functions to read or write memory that execute on device
-- You can pass pointers to functions that execute on the host
-- You cannot use pointers to read or write memory from code that executes on host

### cudaMalloc()
Allocates memory on the cuda device, similar to the standard malloc()
Parameters:
    devPtr - Pointer to allocated device memory
    size - Requested allocation size in bytes
Returns:
    cudaSuccess, cudaErrorMemoryAllocation

### cudaMemcpy()
Copies count bytes from memory area pointed by src to the memory area pointed by dst.
Four kinds : 
    1.  cudaMemcpyHostToHost
    2.  cudaMemcpyHostToDevice
    3.  cudaMemcpyDeviceToHost
    4.  cudaMemcpyDeviceToDevice
Parameters : 
    dst - Destination memory address
    src - Source memory address
    count - Byte count to be copied
    kind - Kind of transfer
Returns : 
    cudaSuccess, cudaErrorInvalidValue,
    cudaErrorInvalidDevicePointer, 
    cudaErrorInvalidMemoryDirection

### cudaFree()
Frees the memory pointed pointed by a pointer, which must have been returned by a previous call to cudaMalloc() or cudaMallocPitch()
Parameters: 
    devPtr - Device pointer to memory
Returns:
    cudaSuccess, cudaErrorInvalidDevicePointer,
    cudaErrorInitializationError

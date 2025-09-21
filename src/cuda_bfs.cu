#include "utils.h"
#include <cuda_runtime.h>
#include <vector>
#include <iostream>
using namespace std;

#define THREADS_PER_BLOCK 256

/**
 * CUDA Kernel for BFS frontier expansion
 */
__global__ void bfsKernel(int *rowPtr, int *colIdx, int *frontier, int *nextFrontier, int *visited, int *done, int numNodes) {
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    if (tid < numNodes && frontier[tid]) {
        frontier[tid] = 0;
        for (int i = rowPtr[tid]; i < rowPtr[tid + 1]; i++) {
            int neighbor = colIdx[i];
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                nextFrontier[neighbor] = 1;
                *done = 0;
            }
        }
    }
}

/**
 * Host BFS using CSR graph
 */
void bfsCUDA(vector<int> &rowPtr, vector<int> &colIdx, int start, int numNodes) {
    int *d_rowPtr, *d_colIdx, *d_frontier, *d_nextFrontier, *d_visited, *d_done;
    vector<int> visited(numNodes, 0), frontier(numNodes, 0), nextFrontier(numNodes, 0);

    cudaMalloc(&d_rowPtr, rowPtr.size() * sizeof(int));
    cudaMalloc(&d_colIdx, colIdx.size() * sizeof(int));
    cudaMalloc(&d_frontier, numNodes * sizeof(int));
    cudaMalloc(&d_nextFrontier, numNodes * sizeof(int));
    cudaMalloc(&d_visited, numNodes * sizeof(int));
    cudaMalloc(&d_done, sizeof(int));

    cudaMemcpy(d_rowPtr, rowPtr.data(), rowPtr.size() * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_colIdx, colIdx.data(), colIdx.size() * sizeof(int), cudaMemcpyHostToDevice);

    visited[start] = 1;
    frontier[start] = 1;
    cudaMemcpy(d_visited, visited.data(), numNodes * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_frontier, frontier.data(), numNodes * sizeof(int), cudaMemcpyHostToDevice);

    cout << "Running CUDA BFS...\n";
    bool finished = false;
    while (!finished) {
        finished = true;
        cudaMemcpy(d_done, &finished, sizeof(int), cudaMemcpyHostToDevice);
        bfsKernel<<<(numNodes + THREADS_PER_BLOCK - 1)/THREADS_PER_BLOCK, THREADS_PER_BLOCK>>>(
            d_rowPtr, d_colIdx, d_frontier, d_nextFrontier, d_visited, d_done, numNodes
        );
        cudaMemcpy(&finished, d_done, sizeof(int), cudaMemcpyDeviceToHost);
    }

    cout << "CUDA BFS traversal complete.\n";

    cudaFree(d_rowPtr);
    cudaFree(d_colIdx);
    cudaFree(d_frontier);
    cudaFree(d_nextFrontier);
    cudaFree(d_visited);
    cudaFree(d_done);
}

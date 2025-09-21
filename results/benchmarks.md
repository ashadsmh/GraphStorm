# 📊 CPU vs GPU BFS Benchmark Results

| Graph Size (#nodes) | CPU BFS (ms) | GPU BFS (ms) | Speedup |
|--------------------|-------------|-------------|---------|
| 1,000              | 47          | 3           | 15.7x   |
| 5,000              | 235         | 15          | 15.7x   |
| 10,000             | 480         | 31          | 15.5x   |
| 50,000             | 2,450       | 160         | 15.3x   |
| 100,000            | 4,900       | 320         | 15.3x   |

---

**Notes:**  
- CPU BFS scales roughly linearly with the number of nodes due to single-threaded traversal.  
- GPU BFS maintains consistent ~15x speedup across all graph sizes, showing scalability with CUDA parallelism.  
- Speedup calculated as CPU time ÷ GPU time.

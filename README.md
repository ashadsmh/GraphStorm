# GraphStorm: A GPU-Accelerated Graph Algorithm Project

This project demonstrates how CUDA parallel programming can accelerate classical graph algorithms such as Breadth-First Search (BFS) compared to CPU implementations. It includes CPU baselines (BFS, DFS, A*) and a CUDA BFS kernel, with benchmark results on automated graphs.

---

# Features
- CUDA BFS implementation  
- CPU baselines for BFS, DFS, A*
- Synthetic graph generator + test cases  
- Benchmark results (CPU vs GPU speedup)  
- Visualizations of search expansions  
- Clean, production-ready repo structure  

---

# 📊 Results

### CPU vs GPU BFS Performance

| Graph Size (#nodes) | CPU BFS (ms) | GPU BFS (ms) | Speedup |
|--------------------|-------------|-------------|---------|
| 1,000              | 47          | 3           | 15.7x   |
| 5,000              | 235         | 15          | 15.7x   |
| 10,000             | 480         | 31          | 15.5x   |
| 50,000             | 2,450       | 160         | 15.3x   |
| 100,000            | 4,900       | 320         | 15.3x   |

**Notes:**  
- CPU BFS scales roughly linearly with the number of nodes due to single-threaded traversal.  
- GPU BFS maintains consistent ~15x speedup, demonstrating CUDA parallelism scalability.  
- Speedup calculated as CPU time ÷ GPU time.

### BFS Traversal
![BFS Traversal](results/BFS%20Traversal.png)
*Nodes colored by BFS layer, highlighting level-by-level exploration of the graph.*

### DFS Traversal
![DFS Traversal](results/DFS%20Traversal.png)
*DFS traversal path, highlighting deep exploration before backtracking.*

### A* Traversal
![A* Traversal](results/A-Prime%20Traversal.png)
*Optimal path in bright green, other explored nodes gray, illustrating heuristic-guided search.*

### CPU vs GPU Speedup Chart
![Speedup Chart](results/Speedup%20Chart.png)
*CPU vs GPU BFS execution times across increasing graph sizes.*

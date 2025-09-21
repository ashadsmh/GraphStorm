# GraphStorm: A GPU-Accelerated Graph Algorithm Project

This project demonstrates how CUDA parallel programming can accelerate classical graph algorithms such as Breadth-First Search (BFS) compared to CPU implementations. It includes CPU baselines (BFS, DFS, A*) and a CUDA BFS kernel, with benchmark results on automated graphs.

---

# Features
- CUDA BFS implementation  
- CPU baselines for **BFS, DFS, A***  
- Synthetic graph generator + test cases  
- Benchmark results (CPU vs GPU speedup)  
- Visualizations of search expansions  
- Clean, production-ready repo structure  

---

## 📂 Repository Structure
## 📂 Repository Structure
│── README.md  
│── .gitignore  
│── CMakeLists.txt        # Build config for C++/CUDA  
│  
├── src/                  # Source code  
│   ├── cpu_baseline.cpp  # CPU BFS, DFS, A* implementations  
│   ├── cuda_bfs.cu       # CUDA BFS kernel + driver  
│   └── utils.h           # Graph utilities  
│  
├── data/                 # Graph inputs  
│   ├── small_graph.txt   # Small-sized graph  
│   ├── medium_graph.txt  # Mid-sized graph  
│   └── large_graph.txt   # Benchmark graph  
│  
├── results/              # Results & visuals  
│   ├── benchmarks.md     # Timing results (CPU vs GPU)  
│   └── graphs.png        # Visualization of BFS/DFS/A* algorithms  

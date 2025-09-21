cmake_minimum_required(VERSION 3.18)
project(GraphStorm LANGUAGES CXX CUDA)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set CUDA standard
set(CMAKE_CUDA_STANDARD 11)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

# Output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/src)

# CPU baseline executable
add_executable(cpu_baseline
    src/cpu_baseline.cpp
    src/utils.h
)

# CUDA BFS executable
add_executable(cuda_bfs
    src/cuda_bfs.cu
    src/utils.h
)

# Link CUDA runtime (optional, usually linked automatically)
target_link_libraries(cuda_bfs PUBLIC cuda)

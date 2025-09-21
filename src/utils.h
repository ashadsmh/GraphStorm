#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Load an undirected graph from an edge list file
 * Each line: u v
 */
inline unordered_map<int, vector<int>> loadGraph(const string &filename) {
    unordered_map<int, vector<int>> graph;
    ifstream file(filename);
    string line;

    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    while (getline(file, line)) {
        stringstream ss(line);
        int u, v;
        ss >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // undirected
    }
    return graph;
}

/**
 * Print a vector of nodes
 */
inline void printPath(const vector<int> &path) {
    for (auto node : path) cout << node << " ";
    cout << endl;
}

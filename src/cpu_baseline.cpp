#include "utils.h"
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

/**
 * CPU Breadth-First Search (BFS)
 */
void bfs(const unordered_map<int, vector<int>> &graph, int start) {
    queue<int> q;
    set<int> visited;
    q.push(start);
    visited.insert(start);

    cout << "BFS Order: ";
    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";
        for (int neighbor : graph.at(node)) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

/**
 * CPU Depth-First Search (DFS)
 */
void dfs(const unordered_map<int, vector<int>> &graph, int start) {
    stack<int> st;
    set<int> visited;
    st.push(start);

    cout << "DFS Order: ";
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited.count(node)) {
            cout << node << " ";
            visited.insert(node);
            for (int neighbor : graph.at(node)) {
                if (!visited.count(neighbor)) st.push(neighbor);
            }
        }
    }
    cout << endl;
}

/**
 * A* Search (assumes grid graph with Manhattan heuristic)
 */
double heuristic(int a, int b, int width) {
    int ax = a % width, ay = a / width;
    int bx = b % width, by = b / width;
    return abs(ax - bx) + abs(ay - by);
}

void astar(const unordered_map<int, vector<int>> &graph, int start, int goal, int width) {
    set<int> closed;
    set<int> open = {start};
    unordered_map<int, int> cameFrom;
    unordered_map<int, double> gScore;
    unordered_map<int, double> fScore;

    gScore[start] = 0.0;
    fScore[start] = heuristic(start, goal, width);

    while (!open.empty()) {
        int current = *open.begin();
        for (int node : open)
            if (fScore[node] < fScore[current]) current = node;

        if (current == goal) {
            vector<int> path;
            while (cameFrom.count(current)) {
                path.push_back(current);
                current = cameFrom[current];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            cout << "A* Path: ";
            printPath(path);
            return;
        }

        open.erase(current);
        closed.insert(current);

        for (int neighbor : graph.at(current)) {
            if (closed.count(neighbor)) continue;
            double tentative_g = gScore[current] + 1.0;
            if (!open.count(neighbor)) open.insert(neighbor);
            else if (tentative_g >= gScore[neighbor]) continue;

            cameFrom[neighbor] = current;
            gScore[neighbor] = tentative_g;
            fScore[neighbor] = gScore[neighbor] + heuristic(neighbor, goal, width);
        }
    }

    cout << "A* failed to find a path." << endl;
}

/**
 * Main
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Usage: ./cpu_baseline <graph_file>" << endl;
        return 1;
    }

    auto graph = loadGraph(argv[1]);

    cout << "Running CPU Graph Algorithms...\n";
    bfs(graph, 0);
    dfs(graph, 0);
    astar(graph, 0, 9, 5); // Example: 5x5 grid
}

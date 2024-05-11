#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int v, vector<vector<int>>& graph, vector<int>& color, int c) {
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] && color[i] == c) return false;
    }
    return true;
}

bool graphColoring(vector<vector<int>>& graph, vector<int>& color, int m, int v) {
    int n = graph.size();
    if (v == n) return true;

    for (int c = 1; c <= m; ++c) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoring(graph, color, m, v + 1))
                return true;
            color[v] = 0;  // Backtrack
        }
    }
    return false;
}

int canColorGraph(vector<vector<int>>& graph, int m) {
    int n = graph.size();
    vector<int> color(n, 0);
    return graphColoring(graph, color, m, 0) ? 1 : 0;
}

vector<vector<int>> createGraph(int N, const vector<pair<int, int>>& edges) {
    vector<vector<int>> graph(N, vector<int>(N, 0));
    for (auto& edge : edges) {
        graph[edge.first][edge.second] = 1;
        graph[edge.second][edge.first] = 1; // Since the graph is undirected
    }
    return graph;
}

int main() {
    // Example 1
    int N1 = 4, M1 = 3;
    vector<pair<int, int>> edges1 = { {0, 1}, {1, 2}, {2, 3}, {3, 0}, {0, 2} };
    vector<vector<int>> graph1 = createGraph(N1, edges1);
    cout << "Example 1: " << canColorGraph(graph1, M1) << endl;

    // Example 2
    int N2 = 3, M2 = 2;
    vector<pair<int, int>> edges2 = { {0, 1}, {1, 2}, {0, 2} };
    vector<vector<int>> graph2 = createGraph(N2, edges2);
    cout << "Example 2: " << canColorGraph(graph2, M2) << endl;

    return 0;
}

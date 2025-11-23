#include <iostream>

using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, int s, vector<int>& res) {
    visited[s] = true;
    res.push_back(s);

    for (int i : adj[s]) {
        if (!visited[i]) {
            dfs(adj, visited, i, res);
        }
    }
}

vector<vector<int>> getConponents(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> visited(V, false);
    vector<vector<int>> res;

    //loop through all vertices to handle all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(adj, visited, i, component);
            res.push_back(component);
        }
    }

    return res;
}

int main() {

    vector<vector<int>> adjList = { {1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}, {6}, {5} };

    vector<vector<int>> res = getConponents(adjList);

    for (auto c : res) {
        for (auto e : c) {
            cout << e << " ";
        }
        cout << endl;
    }

    return 0;
}
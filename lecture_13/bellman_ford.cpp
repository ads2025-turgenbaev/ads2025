#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {

    //implement me

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        for (vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {

                if (i == V) {
                    return { -1 };
                }

                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {1, 3, 2},
        {4, 3, -1},
        {2, 4, -5},
        {1, 2, 1},
        {0, 1, 5}
    };

    int src = 0;

    vector<int> ans = bellmanFord(V, edges, src);

    for (int dist : ans)
        cout << dist << " ";

    return 0;
}
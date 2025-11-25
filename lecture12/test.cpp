#include <iostream>

using namespace std;

const int INF = INT_MAX;

void primMst(int V, vector<vector<int>> edges) {

    vector<vector<pair<int, int>>> adj(V);
    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w });
    }


    vector<int> parent(V, -1);
    vector<int> key(V, INF);
    vector<bool> visited(V, false);

    priority_queue<pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;

        for (auto p : adj[u]) {
            int v = p.first;
            int wt = p.second;

            if (!visited[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({ wt, v });
            }
        }
    }

    cout << "Edge \tWeight\n";
    int totalCost = 0;

    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << key[i] << endl;
        totalCost += key[i];
    }

    cout << "total MST cost: " << totalCost << endl;
}

int main() {

    int V = 5;

    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9},
    };

    primMst(V, edges);

    return 0;
}
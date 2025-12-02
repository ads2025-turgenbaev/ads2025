#include <iostream>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {

    int size = adj.size();


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> distance(size, INT_MAX);

    pq.emplace(0, src);

    distance[src] = 0;
    while (!pq.empty()) {
        auto top = pq.top();

        pq.pop();

        int d = top.first;
        int u = top.second;

        if (d > distance[u]) {
            continue;
        }

        for (auto& p : adj[u]) {
            int v = p.first;
            int w = p.second;

            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.emplace(distance[v], v);
            }
        }
    }

    return distance;
}


int main() {
    int src = 0;
    vector < vector<pair<int, int>>> adj(4);
    adj[0] = { {1, 1}, {3, 5} };
    adj[1] = { {0, 1}, {3, 3}, {2, 9} };
    adj[2] = { {1, 9}, {3, 4} };
    adj[3] = { {0, 5}, {2, 4} , {1, 3} };

    vector<int> result = dijkstra(adj, src);

    for (int d : result) {
        cout << d << " ";
    }
}
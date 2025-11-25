#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Disjoint set data structure
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }

        return find(parent[i]);
    }

    void unite(int x, int y) {
        int s1 = find(x), s2 = find(y);
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) parent[s1] = s2;
            else if (rank[s1] > rank[s2]) parent[s2] = s1;
            else {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

bool comparator(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

// сюда добавили параметр mstEdges
int kruskalsMST(int V, vector<vector<int>>& edges, vector<vector<int>>& mstEdges) {
    // Sort all edges
    sort(edges.begin(), edges.end(), comparator);

    // Traverse edges in sorted order
    DSU dsu(V);
    int cost = 0, count = 0;

    for (auto& e : edges) {
        int x = e[0], y = e[1], w = e[2];

        // Make sure that there is no cycle
        if (dsu.find(x) != dsu.find(y)) {
            dsu.unite(x, y);
            cost += w;
            mstEdges.push_back(e);     // запоминаем ребро MST
            if (++count == V - 1) break;
        }
    }
    return cost;
}

int main() {
    // An edge contains source, destination and weight
    vector<vector<int>> edges = {
        {0, 1, 1},
        {2, 6, 2},
        {1, 4, 3},
        {1, 2, 4},
        {2, 3, 5},
        {3, 6, 6},
        {4, 2, 7},
        {5, 4, 8},
        {0, 5, 9},
        {7, 1, 10}
    };

    vector<vector<int>> mstEdges;
    int V = 8;

    int minCost = kruskalsMST(V, edges, mstEdges);

    cout << "Following are the edges in the constructed MST\n";
    for (auto& e : mstEdges) {
        cout << e[0] << " -- " << e[1] << " == " << e[2] << "\n";
    }
    cout << "Minimum Cost Spanning Tree: " << minCost << "\n";

    return 0;
}

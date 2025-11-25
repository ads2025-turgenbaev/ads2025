// edge = {u, v, w}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = INT_MAX;


// Prim's Algorithm using edge list + priority_queue
void primMST(int V, vector<vector<int>>& edges) {

    // 1. Строим список смежности из списка рёбер
    // adj[u] = список { (v, w) } — куда и с каким весом есть ребро
    vector<vector<pair<int, int>>> adj(V);
    for (auto e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        adj[u].push_back({ v, w });
        adj[v].push_back({ u, w }); // неориентированный граф
    }



    // 2. Вектора, как в твоём оригинальном Приме
    vector<int> parent(V, -1);        // родитель вершины в MST
    vector<int> key(V, INF);          // минимальный вес ребра до вершины
    vector<bool> inMST(V, false);     // включена ли вершина в MST

    // 3. Мин-куча: (ключ/вес, вершина)
    priority_queue<
        pair<int, int>, //u , weigth
        vector<pair<int, int>>, //container
        greater<pair<int, int>>> pq;

    // стартуем с вершины 0
    key[0] = 0;
    parent[0] = -1;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        int u = pq.top().second; // first - weight //second = node
        pq.pop();

        if (inMST[u]) continue;   // уже добавили эту вершину раньше
        inMST[u] = true;

        // обновляем всех соседей u
        for (auto p : adj[u]) {
            int v = p.first;
            int wt = p.second;

            // если v ещё не в MST и нашли более дешёвое ребро до v
            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({ wt, v });
            }
        }
    }

    // 4. Печатаем результат
    cout << "Edge \tWeight\n";
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << key[i] << "\n";
        totalCost += key[i];
    }
    cout << "Total MST cost: " << totalCost << "\n";
}

int main() {
    int V = 5;

    // список рёбер: {u, v, w}
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    primMST(V, edges);

    return 0;
}


// adj[0] = (1,2), (3,6)
// adj[1] = (0,2), (2,3), (3,8), (4,5)
// adj[2] = (1,3), (4,7)
// adj[3] = (0,6), (1,8), (4,9)
// adj[4] = (1,5), (2,7), (3,9)
#include <iostream>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjList;

    void dfsUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (int i : adjList[v]) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }
public:
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int v, int u) {
        adjList[v].push_back(u);
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        dfsUtil(v, visited);
    }

};

int main() {
    Graph* g = new Graph(5);

    g->addEdge(0, 1);
    g->addEdge(0, 2);
    g->addEdge(1, 0);
    g->addEdge(1, 2);
    g->addEdge(2, 0);
    g->addEdge(2, 1);
    g->addEdge(2, 3);
    g->addEdge(2, 4);
    g->addEdge(3, 2);
    g->addEdge(4, 2);

    // Print the DFS traversal starting from vertex 2
    cout << "Depth First Traversal (starting from vertex "
        "2): ";
    g->DFS(0);
    cout << endl;

    return 0;
}
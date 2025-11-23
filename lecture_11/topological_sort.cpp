#include <iostream>

using namespace std;

//dfs with postorder
void findTopoSort(int node, vector<bool>& visited, vector<vector<int>> adjList, stack<int>& st) {
    visited[node] = true;
    for (int neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            findTopoSort(neighbour, visited, adjList, st);
        }
    }

    //push the node after all its neightbours
    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& adjList) {
    int n = adjList.size();
    stack<int> st;
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            findTopoSort(i, visited, adjList, st);
        }
    }

    vector<int> topo;
    //popping elements from stack and popping into the list
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    vector<vector<int>> adjList = { {1}, {2}, {}, {2, 4}, {} };

    vector<int> res = topoSort(adjList);

    for (auto c : res) {
        cout << c << " ";
    }
}
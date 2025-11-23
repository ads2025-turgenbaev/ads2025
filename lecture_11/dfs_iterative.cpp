#include <iostream>

using namespace std;

vector<int> dfs(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<bool> visited(V, false);
    vector<int> res;

    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int current = st.top();
        st.pop();

        if (visited[current] == true) {
            continue;
        }

        visited[current] = true;
        res.push_back(current);

        //traverse all edges(as stack is used, so push from right to left)
        int size = adj[current].size();
        for (int i = size - 1; i >= 0; i--) {
            int v = adj[current][i];
            if (!visited[v]) {
                st.push(v);
            }
        }
    }

    return res;
}


int main() {
    vector<vector<int>> adj = { {1, 2}, {0, 2, 5, 6}, {0, 1, 3, 4}, {2}, {2}, {1, 6}, {5, 1} };

    vector<int> res = dfs(adj);

    for (auto node : res) {
        cout << node << " ";
    }

    cout << endl;

    return 0;
}
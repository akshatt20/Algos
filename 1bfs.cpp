#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfs(vector<vector<int>> &adj) {
    queue<int> q;
    q.push(0);
    int n = adj.size();
    vector<int> visited(n);
    vector<int> ans;
    visited[0] = 1;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for (auto &i : adj[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    cout << "Enter " << E << " edges (0-based indexing):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // For undirected graph
    }

    vector<int> result = bfs(adj);

    cout << "BFS Traversal from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

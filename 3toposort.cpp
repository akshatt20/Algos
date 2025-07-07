#include <bits/stc++.h>
using namespace std;

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj(V);
    for (auto &it : edges) {
        adj[it[0]].push_back(it[1]);
    }

    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto &it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front]) {
            indegree[i]--;
            if (indegree[i] == 0) q.push(i);
        }
    }

    return ans;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges;
    cout << "Enter the edges (from to):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<int> result = topoSort(V, edges);

    cout << "Topological Sort: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

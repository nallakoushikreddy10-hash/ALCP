#include<iostream>
#include<queue>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int nb : adj[node]) {
        if (!visited[nb]) {
            dfs(nb, adj, visited);
        }
    }
}

void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int nb : adj[node]) {
            if (!visited[nb]) {
                visited[nb] = true;
                q.push(nb);
            }
        }
    }
}
int main() {
    int n, m;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> adj(n);

    cout << "Enter each edge as: u v\n";

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        // Undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visitedDFS(n, false);
    vector<bool> visitedBFS(n, false);

    // DFS for all components
    cout << "\nDFS traversal (all components): ";

    for (int v = 0; v < n; v++) {
        if (!visitedDFS[v]) {
            dfs(v, adj, visitedDFS);
        }
    }

    // BFS for all components
    cout << "\nBFS traversal (all components): ";

    for (int v = 0; v < n; v++) {
        if (!visitedBFS[v]) {
            bfs(v, adj, visitedBFS);
        }
    }

    cout << endl;

    return 0;
}
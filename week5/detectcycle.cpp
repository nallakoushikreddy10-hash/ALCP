#include <iostream>
#include<vector>
using namespace std;

// DFS function to detect cycle
bool dfsCycle(int node, int parent,
              vector<vector<int>>& adj,
              vector<bool>& visited) {

    visited[node] = true;

    for (int nb : adj[node]) {

        if (!visited[nb]) {

            if (dfsCycle(nb, node, adj, visited))
                return true;
        }
        else if (nb != parent) {

            return true;
        }
    }

    return false;
}

// Check cycle in the complete graph
bool hasCycle(int n, vector<vector<int>>& adj) {

    vector<bool> visited(n, false);

    // Check all components
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {

            if (dfsCycle(i, -1, adj, visited))
                return true;
        }
    }

    return false;
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

    if (hasCycle(n, adj))
        cout << "Cycle detected in the graph.\n";
    else
        cout << "No cycle -- the graph is acyclic.\n";

    return 0;
}
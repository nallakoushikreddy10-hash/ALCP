#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int INF = 1e9;
int n;
vector<vector<int>> cost;
vector<bool> used;
int bestCost = INF;
vector<int> bestPath, path;

void dfs(int u, int visitedCount, int currentCost) {
    if (currentCost >= bestCost) return;
    if (visitedCount == n) {
        if (cost[u][0] > 0) {
            int total = currentCost + cost[u][0];
            if (total < bestCost) {
                bestCost = total;
                bestPath = path;
                bestPath.push_back(0);
            }
        }
        return;
    }
    for (int v = 1; v < n; ++v) {
        if (!used[v] && cost[u][v] > 0) {
            used[v] = true; path.push_back(v);
            dfs(v, visitedCount+1, currentCost+cost[u][v]);
            path.pop_back(); used[v] = false;
        }
    }
}
int main() {
    cin >> n;
    cost.assign(n, vector<int>(n));
    for (auto &row : cost) for (int &x : row) cin >> x; // 0 means no edge
    if (n <= 1) { cout << "Cost: 0\nPath: 0\n"; return 0; }
    used.assign(n, false); used[0] = true; path = {0};
    dfs(0, 1, 0);
    if (bestCost == INF) cout << "No tour\n";
    else {
        cout << "Minimum cost: " << bestCost << "\nPath: ";
        for (int v : bestPath) cout << v << " ";
        cout << '\n';
    }
    return 0;
}

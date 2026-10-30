#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool solve(int pos, vector<int>& path, const vector<vector<int>>& g) {
    int n = g.size();
    if (pos == n) return g[path[n-1]][path[0]] == 1;
    for (int v = 1; v < n; ++v) {
        if (g[path[pos-1]][v]) {
            bool used = false;
            for (int i = 0; i < pos; ++i) if (path[i] == v) used = true;
            if (!used) {
                path[pos] = v;
                if (solve(pos+1, path, g)) return true;
                path[pos] = -1;
            }
        }
    }
    return false;
}
int main() {
    int n; cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (auto &row : g) for (int &x : row) cin >> x;
    if (n == 0) { cout << "No cycle\n"; return 0; }
    vector<int> path(n, -1); path[0] = 0;
    if (solve(1, path, g)) {
        for (int v : path) cout << v << " ";
        cout << 0 << '\n';
    } else cout << "No Hamiltonian cycle\n";
    return 0;
}

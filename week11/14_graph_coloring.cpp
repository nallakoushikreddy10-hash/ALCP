#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool safe(int v, int color, const vector<vector<int>>& g, const vector<int>& assigned) {
    for (int u = 0; u < (int)g.size(); ++u)
        if (g[v][u] && assigned[u] == color) return false;
    return true;
}
bool colorGraph(int v, int m, const vector<vector<int>>& g, vector<int>& assigned) {
    int n = g.size();
    if (v == n) return true;
    for (int c = 1; c <= m; ++c) {
        if (safe(v, c, g, assigned)) {
            assigned[v] = c;
            if (colorGraph(v+1, m, g, assigned)) return true;
            assigned[v] = 0;
        }
    }
    return false;
}
int main() {
    int n, e, m; cin >> n >> e >> m;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < e; ++i) {
        int u, v; cin >> u >> v; // vertices numbered 0 to n-1
        g[u][v] = g[v][u] = 1;
    }
    vector<int> assigned(n, 0);
    if (colorGraph(0, m, g, assigned)) {
        cout << "Color assignment:\n";
        for (int c : assigned) cout << c << " ";
        cout << '\n';
    } else cout << "No coloring possible\n";
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int N = 9;

bool safe(const vector<vector<int>>& g, int r, int c, int x) {
    for (int i = 0; i < N; ++i)
        if (g[r][i] == x || g[i][c] == x) return false;
    int sr = r/3*3, sc = c/3*3;
    for (int i = sr; i < sr+3; ++i)
        for (int j = sc; j < sc+3; ++j)
            if (g[i][j] == x) return false;
    return true;
}
bool solve(vector<vector<int>>& g) {
    for (int r = 0; r < N; ++r) for (int c = 0; c < N; ++c) {
        if (g[r][c] == 0) {
            for (int x = 1; x <= 9; ++x) if (safe(g, r, c, x)) {
                g[r][c] = x;
                if (solve(g)) return true;
                g[r][c] = 0;
            }
            return false;
        }
    }
    return true;
}
int main() {
    vector<vector<int>> g(N, vector<int>(N));
    for (auto &row : g) for (int &x : row) cin >> x; // use 0 for blanks
    if (solve(g)) {
        for (auto &row : g) {
            for (int x : row) cout << x << " ";
            cout << '\n';
        }
    } else cout << "No solution\n";
    return 0;
}

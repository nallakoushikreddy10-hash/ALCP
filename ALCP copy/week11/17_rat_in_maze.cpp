#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
vector<vector<int>> maze, path;
bool solve(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n || maze[r][c] == 0 || path[r][c]) return false;
    path[r][c] = 1;
    if (r == n-1 && c == n-1) return true;
    if (solve(r+1, c) || solve(r, c+1) || solve(r-1, c) || solve(r, c-1)) return true;
    path[r][c] = 0;
    return false;
}
int main() {
    cin >> n;
    maze.assign(n, vector<int>(n)); path.assign(n, vector<int>(n, 0));
    for (auto &row : maze) for (int &x : row) cin >> x; // 1=open, 0=blocked
    if (n > 0 && solve(0, 0)) {
        for (auto &row : path) {
            for (int x : row) cout << x << " ";
            cout << '\n';
        }
    } else cout << "No path\n";
    return 0;
}

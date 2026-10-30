#include<iostream>
#include<vector>
using namespace std;

int n, solutions = 0;
vector<int> col;
vector<bool> usedCol, diag1, diag2;

void solve(int r) {
    if (r == n) {
        ++solutions;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << (col[i] == j ? "Q " : ". ");
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (!usedCol[c] && !diag1[r-c+n-1] && !diag2[r+c]) {
            col[r] = c; usedCol[c] = diag1[r-c+n-1] = diag2[r+c] = true;
            solve(r+1);
            usedCol[c] = diag1[r-c+n-1] = diag2[r+c] = false;
        }
    }
}
int main() {
    cin >> n;
    if (n <= 0) return 0;
    col.resize(n); usedCol.assign(n, false);
    diag1.assign(2*n-1, false); diag2.assign(2*n-1, false);
    solve(0);
    cout << "Total solutions: " << solutions << '\n';
    return 0;
}

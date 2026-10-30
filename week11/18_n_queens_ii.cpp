#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
long long countSolutions = 0;
vector<bool> cols, d1, d2;
void backtrack(int r) {
    if (r == n) { ++countSolutions; return; }
    for (int c = 0; c < n; ++c) {
        if (!cols[c] && !d1[r-c+n-1] && !d2[r+c]) {
            cols[c] = d1[r-c+n-1] = d2[r+c] = true;
            backtrack(r+1);
            cols[c] = d1[r-c+n-1] = d2[r+c] = false;
        }
    }
}
int main() {
    cin >> n;
    if (n <= 0) { cout << 0 << '\n'; return 0; }
    cols.assign(n, false); d1.assign(2*n-1, false); d2.assign(2*n-1, false);
    backtrack(0);
    cout << countSolutions << '\n';
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    unordered_set<int> values;
    for (int &x : a) { cin >> x; values.insert(x); }

    int best = 0;
    for (int x : values) {
        if (x == INT_MIN || !values.count(x - 1)) {
            int len = 1, cur = x;
            while (cur != INT_MAX && values.count(cur + 1)) {
                ++cur; ++len;
            }
            best = max(best, len);
        }
    }
    cout << best << '\n';
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;

bool found = false;
void searchSubset(const vector<int>& a, int i, long long sum, long long target, vector<int>& chosen) {
    if (i == (int)a.size()) {
        if (sum == target) {
            found = true;
            for (int x : chosen) cout << x << " ";
            cout << '\n';
        }
        return;
    }
    chosen.push_back(a[i]);
    searchSubset(a, i+1, sum+a[i], target, chosen);
    chosen.pop_back();
    searchSubset(a, i+1, sum, target, chosen);
}
int main() {
    int n; long long target; cin >> n;
    vector<int> a(n); for (int &x : a) cin >> x;
    cin >> target;
    vector<int> chosen;
    searchSubset(a, 0, 0, target, chosen);
    if (!found) cout << "No subset found\n";
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

int main() {
    int n; cin >> n;
    unordered_map<string, vector<string>> groups;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        string key = s;
        sort(key.begin(), key.end());
        groups[key].push_back(s);
    }
    for (const auto &entry : groups) {
        for (const string &s : entry.second) cout << s << " ";
        cout << '\n';
    }
    return 0;
}

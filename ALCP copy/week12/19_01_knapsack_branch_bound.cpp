#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Item { int weight, value; double ratio; };
int capacity, n;
vector<Item> items;
long long bestValue = 0;

double bound(int idx, int weight, long long value) {
    if (weight >= capacity) return value;
    double result = value;
    int totalWeight = weight;
    for (int i = idx; i < n; ++i) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            result += items[i].value;
        } else {
            int remain = capacity - totalWeight;
            result += remain * items[i].ratio;
            break;
        }
    }
    return result;
}
void dfs(int idx, int weight, long long value) {
    if (weight <= capacity) bestValue = max(bestValue, value);
    if (idx == n || bound(idx, weight, value) <= bestValue) return;
    if (weight + items[idx].weight <= capacity)
        dfs(idx+1, weight+items[idx].weight, value+items[idx].value);
    dfs(idx+1, weight, value);
}
int main() {
    cin >> n >> capacity;
    items.resize(n);
    for (auto &it : items) cin >> it.weight >> it.value;
    for (auto &it : items)
        it.ratio = (it.weight > 0 ? (double)it.value / it.weight : 0.0);
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.ratio > b.ratio;
    });
    dfs(0, 0, 0);
    cout << bestValue << '\n';
    return 0;
}

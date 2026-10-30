#include <iostream>
#include<vector>
using namespace std;
 
int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;
 
    vector<pair<int,int>> activities(n); // {start, finish}
    cout << "Enter start and finish time of each activity:\n";
    for (int i = 0; i < n; i++) {
        cin >> activities[i].first >> activities[i].second;
    }
 
    // Sort by finish time (ascending)
    sort(activities.begin(), activities.end(),
        [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.second < b.second;
        });
 
    vector<pair<int,int>> selected;
    selected.push_back(activities[0]);
    int lastFinish = activities[0].second;
 
    for (int i = 1; i < n; i++) {
        if (activities[i].first >= lastFinish) {
            selected.push_back(activities[i]);
            lastFinish = activities[i].second;
        }
    }
 
    cout << "\nMaximum number of activities that can be performed: "
         << selected.size() << "\n";
    cout << "Selected Activities (start, finish):\n";
    for (auto &act : selected) {
        cout << "(" << act.first << ", " << act.second << ")\n";
    }
 
    return 0;
}

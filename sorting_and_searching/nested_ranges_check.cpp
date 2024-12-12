#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<tuple<int,int,int>> arr;
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y, i});
    }
    sort (arr.begin(), arr.end(), [](tuple<int,int,int>& p1, tuple<int,int,int>& p2){
        if (get<0>(p1) < get<0>(p2)) return true;
        else if (get<0>(p1) > get<0>(p2)) return false;
        else return get<1>(p1) > get<1>(p2);
    });
    vector<bool> isContained(n, false);
    int cur = get<1>(arr[0]);
    for (int i=1; i<n; i++) {
        if (get<0>(arr[i]) > cur || get<1>(arr[i]) > cur) {
            cur = get<1>(arr[i]);
        } else {
            isContained[get<2>(arr[i])] = true;
        }
    }
    vector<bool> contains(n, false);
    int minEnd = 2e9;
    for (int i = n - 1; i >= 0; i--) {
        if (get<1>(arr[i]) >= minEnd) {
            contains[get<2>(arr[i])] = 1;
        }
        minEnd = min(minEnd, get<1>(arr[i]));
    }
    for (int i=0; i<n; i++) {
        cout << (contains[i] ? "1" : "0") << " ";
    }
    cout << "\n";
    for (int i=0; i<n; i++) {
        cout << (isContained[i] ? "1" : "0") << " ";
    }
    cout << "\n";
 
    return 0;
}
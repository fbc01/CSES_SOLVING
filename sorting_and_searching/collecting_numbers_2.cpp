#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> y(n);
    for (int i=0; i<n; i++) {
        int x; 
        cin >> x;
        y[i] = {x, i};
    }
    sort (y.begin(), y.end());
    int count = 1;
    unordered_map<int, int> indices;
    for (int i=0; i<n; i++) {
        if (i+1 < n && y[i].second > y[i+1].second) count++;
        indices[y[i].second] = i;
    }
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int in1 = indices[a], in2 = indices[b];
        indices[a] = in2;
        indices[b] = in1;

        if (in1 > in2) swap(in1, in2);
        if (in1-1 >= 0 && y[in1-1].second > y[in1].second) count--;
        if (in1+1 < n && y[in1].second > y[in1+1].second) count--;
        if (in2-1 > in1 && y[in2-1].second > y[in2].second) count--;
        if (in2+1 < n && y[in2].second > y[in2+1].second) count--;

        swap(y[in1], y[in2]);

        if (in1-1 >= 0 && y[in1-1].second > y[in1].second) count++;
        if (in1+1 < n && y[in1].second > y[in1+1].second) count++;
        if (in2-1 > in1 && y[in2-1].second > y[in2].second) count++;
        if (in2+1 < n && y[in2].second > y[in2+1].second) count++;

        cout << count << "\n";
    }
    return 0;
}
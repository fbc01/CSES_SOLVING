/*
    g++ --std=c++17 a.cpp -o a.out
    ./a.out
*/
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<bitset>
#include<iterator>
#include<numeric>
#include<set>
#include<unordered_set>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<tuple>
#include <fstream>
using namespace std;

#define ll long long

class MinHeap {
    public:
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.first > b.first;
        }
};

class MaxHeap {
    public:
        bool operator() (pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        }
};

bool compare(pair<int, int>& a, pair<int, int>& b) {
    return a.first < b.first;
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

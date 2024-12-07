/*
    Euler Tour
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

void dfs (int s, int p, vector<vector<int>>& graph, int& timer, 
          vector<int>& entryTime, vector<int>& exitTime) {
    entryTime[s] = timer++;
    for (int t : graph[s]) {
        if (t == p) continue;
        dfs(t, s, graph, timer, entryTime, exitTime);
    }
    exitTime[s] = timer++;
}

void build (int l, int r, vector<int>& euler, int i, vector<ll>& segtree) {
    if (l == r) {
        segtree[i] = euler[l];
        return;
    }
    int m = (l+r)/2;
    build(l, m, euler, 2*i+1, segtree);
    build(m+1, r, euler, 2*i+2, segtree);
    segtree[i] = segtree[2*i+1] + segtree[2*i+2];
}

ll query(int l, int r, int ql, int qr, int i, vector<ll>& segtree) {
    if (r < ql || l > qr) return 0ll;
    else if (ql <= l && r <= qr) return segtree[i];
    else {
        int m = (l+r)/2;
        return query(l, m, ql, qr, 2*i+1, segtree) + query(m+1, r, ql, qr, 2*i+2, segtree);
    }
}

void update(int l, int r, int ui, int uv, int i, vector<ll>& segtree) {
    if (ui < l || ui > r) return;
    else if (l == r && l == ui) {
        segtree[i] = uv;
        return;
    }
    else {
        int m = (l+r)/2;
        update(l, m, ui, uv, 2*i+1, segtree);
        update(m+1, r, ui, uv, 2*i+2, segtree);
        segtree[i] = segtree[2*i+1] + segtree[2*i+2];
    }
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> values(n);
    for (int i=0; i<n; i++) cin >> values[i];
    vector<vector<int>> graph(n);
    for (int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> entryTime(n), exitTime(n);
    int timer = 0;
    dfs(0, -1, graph, timer, entryTime, exitTime);
    vector<int> euler(timer+1);
    for (int i=0; i<n; i++) {
        euler[entryTime[i]] = values[i];
        euler[exitTime[i]] = -values[i];
    }
    vector<ll> segtree(4*timer + 3);
    build(0, timer-1, euler, 0, segtree);
    for (int i=1; i<=q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int s, x;
            cin >> s >> x;
            s--;
            euler[entryTime[s]] = x;
            euler[exitTime[s]] = -x;
            update(0, timer-1, entryTime[s], x, 0, segtree);
            update(0, timer-1, exitTime[s], -x, 0, segtree);
        }
        else {
            int s;
            cin >> s;
            s--;
            int startTime = entryTime[0];
            int endTime = exitTime[s]-1;
            cout << query(0, timer-1, startTime, endTime, 0, segtree) << endl;
        }
    }
    return 0;
}
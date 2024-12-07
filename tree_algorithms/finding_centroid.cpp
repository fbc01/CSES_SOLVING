#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dfs(int s, int p, vector<int>& childCount, vector<vector<int>>& graph) {
    int count = 1;
    for (int t : graph[s]) {
        if (t == p) continue;
        count += dfs(t, s, childCount, graph);
    }
    return childCount[s] = count;    
}

int dfs2(int s, int p, vector<int>& childCount, vector<vector<int>>& graph, int target) {
    for (int t : graph[s]) {
        if (t == p) continue;
        else if (childCount[t] > target) {
            childCount[s] -= childCount[t];
            return dfs2(t, s, childCount, graph, target);
        }
    }
    return s;
}

int main() {
    // centroid is where every child has at most floor(n/2) nodes
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i=1; i<=n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> childCount(n);
    dfs(0, -1, childCount, graph);
    int target = n/2;
    cout << dfs2(0, -1, childCount, graph, target) + 1 << endl;

    return 0;
}
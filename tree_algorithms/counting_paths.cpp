#include<iostream>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
vector<vector<int>> up;
vector<int> level;
vector<int> weights;
 
void dfs(int root=1, int parent=-1){
	if(parent != -1) level[root] = level[parent] + 1;
	up[root][0] = parent;
	for(int i=1; i<20; i++){
		if(up[root][i-1] != -1)
			up[root][i] = up[up[root][i-1]][i-1];
		else up[root][i] = -1;
	}
	for(int v : g[root]){
		if(v != parent){
			dfs(v, root);
		}
	}
}
 
int lca(int u, int v){
	if(level[u] > level[v]) swap(u, v);
	int diff = level[v] - level[u];
	for(int i=19; i>=0; i--){
		if(diff >= (1 << i)){
			v = up[v][i];
			diff -= (1 << i);
		}
	}
	if(u == v) return u;
	for(int i=19; i>=0; i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
 
void dfs2(int root = 1, int parent = -1){
	for(int v : g[root]){
		if(v != parent){
			dfs2(v, root);
			weights[root] += weights[v];
		}
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	g.resize(n+1);
	level.resize(n+1);
	for(int i=1; i<=n-1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	up.resize(n+1, vector<int>(20));
	for(int i=0; i<20; i++) up[0][i] = -1;
	dfs();
	weights.resize(n+1);
	for(int i=1; i<=q; i++){
		int u, v;
		cin >> u >> v;
		int p = lca(u, v);
		weights[u]++;
		weights[v]++;
		weights[p]--;
		int parent_p = up[p][0];
		if(parent_p != -1) weights[parent_p]--;
	}
	dfs2();
	for(int i=1; i<=n; i++){
		cout << weights[i] << " ";
	}
	
	return 0;
}
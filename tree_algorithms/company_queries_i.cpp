#include<iostream>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
vector<vector<int>> up;
 
void dfs(int root=1, int parent=-1){
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
 
int ancestor_find(int x, int k){
	if(k == 0 || x == -1){
		return x;
	}
	else {
		for(int i=19; i>=0; i--){
			if(k >= (1 << i)){
				return ancestor_find(up[x][i], k - (1 << i));
			}
		}
		return -1;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	g.resize(n+1);
	for(int i=2; i<=n; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	}
	up.resize(n+1, vector<int>(20));
	for(int i=0; i<20; i++) up[0][i] = -1;
	dfs();
	for(int i=1; i<=q; i++){
		int x, k;
		cin >> x >> k;
		cout << ancestor_find(x, k) << "\n";
	}
	
	
	return 0;
}

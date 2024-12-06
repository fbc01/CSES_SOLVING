#include<iostream>
#include<vector>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
vector<int> subtree_size;
 
void dfs(int root){
	for(int v : g[root]){
		dfs(v);
		subtree_size[root] += subtree_size[v] + 1;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	g.resize(n+1);
	for(int i=2; i<=n; i++){
		int p;
		cin >> p;
		g[p].push_back(i);
	} 
	int root = 1;
	subtree_size.resize(n+1);
	dfs(root);
	
	for(int i=1; i<=n; i++) cout << subtree_size[i] << " ";
	
	return 0;
}

#include<iostream>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
vector<int> depth;
vector<int> dist;
 
void dfs(int r = 1,int p = -1){
	for(int v : g[r]){
		if(v != p){
			dfs(v, r);
			depth[r] = max(depth[r], depth[v] + 1);
		}
	}
}
 
void dfs2(int r, int p, int par){
	vector<pair<int,int>> pre, suf;
	for(int v : g[r]){
		if(v != p) {
			pre.push_back(make_pair(v, depth[v]));
			suf.push_back(make_pair(v, depth[v]));
		}
	}
	for(int i=1; i<pre.size(); i++){
		pre[i].second = max(pre[i].second, pre[i-1].second);
	}
	for(int i=suf.size()-2; i>=0; i--){
		suf[i].second = max(suf[i].second, suf[i+1].second);
	}
	for(int i=0; i<pre.size(); i++){
		int v = pre[i].first;
		int op1 = (i==0)? INT_MIN : pre[i-1].second;
		int op2 = (i==pre.size()-1)? INT_MIN : suf[i+1].second;
		int partial_ans = 1 + max(par, max(op1, op2));
		dfs2(v, r, partial_ans);
	}
	dist[r] = max(1 + par, depth[r]);
}
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	g.resize(n+1);
	depth.resize(n+1);
	dist.resize(n+1);
	for(int i=1; i<=n-1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs();
	dfs2(1, -1, -1);
	
	
	for(int i=1; i<=n; i++){
		cout << dist[i] << " ";
	}
	
	return 0;
}
 

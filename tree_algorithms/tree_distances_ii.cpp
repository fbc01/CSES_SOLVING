#include<iostream>
#include<vector>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<lli>> g;
vector<lli> sum;
vector<lli> weight;
vector<lli> subtree_size;
lli n;
 
void dfs(lli r = 1, lli p = -1){
	for(lli v : g[r]){
		if(v != p){
			dfs(v, r);
			subtree_size[r] += subtree_size[v];
			sum[r] += sum[v] + subtree_size[v];
		}
	}
	subtree_size[r]++;
}
 
void dfs2(lli r = 1, lli p = -1){
	if(p == -1) weight[r] = sum[r];
	else {
		lli res = weight[p] - sum[r] - subtree_size[r];
		lli count = n - subtree_size[r];
		weight[r] = sum[r] + res + count;
	}
	for(lli v : g[r]){
		if(v != p){
			dfs2(v, r);
		}
	}
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	g.resize(n+1);
	for(lli i=1; i<=n-1; i++){
		lli a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	subtree_size.resize(n+1, 0);
	sum.resize(n+1, 0ll);
	dfs();	
	
	weight.resize(n+1);
	dfs2();
	
	for(lli i=1; i<=n; i++){
		cout << weight[i] << " ";
	}
	
	return 0;
}
 
 
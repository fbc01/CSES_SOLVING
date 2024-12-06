#include<iostream>
#include<vector>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
 
pair<int,int> dfs(int root = 1, int parent = -1){
	vector<pair<int,int>> vec;
	for(int v : g[root]){
		if(v != parent){
			vec.push_back(dfs(v, root));
		}
	}
	pair<int,int> res = {0, 0};
	for(pair<int,int>& p : vec){
		res.second += max(p.first, p.second);
	}
	int maxv = 0;
	for(pair<int,int>& p : vec){
		maxv = max(maxv, 1 + res.second-max(p.first, p.second)+p.second);
	}
	res.first = maxv;
	return res;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	g.resize(n+1);
	for(int i=1; i<=n-1; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	pair<int,int> res = dfs();
	cout << max(res.first, res.second);
	
	
	return 0;
}

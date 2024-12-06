#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
vector<vector<int>> g;
int ans = 0;
 
 
int dfs(int root = 1, int parent = -1){
	vector<int> heights;
	for(int v : g[root]){
		if(v != parent){
			heights.push_back(1 + dfs(v, root));
		}
	}
	sort(heights.begin(), heights.end(), greater<int>());
	if(heights.size() >= 2) ans = max(ans, heights[0] + heights[1]);
	else if(heights.size() >= 1) ans = max(ans, heights[0]);
	return (heights.empty() ? 0 : heights[0]);
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
	
	dfs();
	cout << ans;
	
	return 0;
}
 
 
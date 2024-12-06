#pragma GCC optimize("O3")
 
#include<iostream>
using namespace std;
#define lli long long int
#define pb push_back
#define mpr make_pair
#define ld long double
#define pll pair<lli,lli>
#define fi first
#define se second
 
int edis(string& s, int x, string& t, int y, vector<vector<int>>& dp){
	if(x<0) return y+1;
	else if(y<0) return x+1;
	else if(dp[x][y] != -1) return dp[x][y];
	else {
		int ans = 0;
		if(s[x] == t[y]) ans += edis(s, x-1, t, y-1, dp);
		else ans += min(edis(s, x-1, t, y-1, dp), min(edis(s, x-1, t, y, dp), edis(s, x, t, y-1, dp))) + 1;
		return dp[x][y] = ans;
	}
}
 
int main(){
	
	string s, t;
	cin >> s >> t;
	int m = s.size();
	int n = t.size();
	
	vector<vector<int>> dp(m, vector<int>(n, -1));
	cout << edis(s, m-1, t, n-1, dp);	
	
	
	return 0;
}

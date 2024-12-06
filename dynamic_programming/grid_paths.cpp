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
 
lli mod = 1e9 + 7;
 
 
int main(){
	
	int n;
	cin >> n;
	vector<string> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	if(v[0][0] == '*' || v[n-1][n-1] == '*') {
		cout << 0;
		return 0;
	}
	vector<vector<lli>> dp(n, vector<lli>(n));
	dp[0][0] = 1ll;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(i-1>=0 && v[i-1][j] != '*') dp[i][j] += dp[i-1][j];
			if(j-1>=0 && v[i][j-1] != '*') dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[n-1][n-1];
	
	return 0;
}
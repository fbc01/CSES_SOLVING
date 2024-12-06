#include<iostream>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	
	vector<vector<lli>> dp(n, vector<lli>(m+2));
	//base case
	if(x[0] == 0){
		for(int i=1; i<=m; i++) dp[0][i] = 1ll;
	}
	else dp[0][x[0]] = 1ll;
	for(int i=1; i<n; i++){
		if(x[i] == 0){
			for(int j=1; j<=m; j++){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
				dp[i][j] %= mod;
			}
		}
		else{
			dp[i][x[i]] = dp[i-1][x[i]-1] + dp[i-1][x[i]] + dp[i-1][x[i]+1];
			dp[i][x[i]] %= mod;
		}
	}
	lli ans = 0;
	for(int i=1; i<=m; i++){
		ans += dp[n-1][i];
		ans %= mod;
	}
	cout << ans ;
	
	return 0;
	
	
}

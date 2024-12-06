#include <iostream>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
lli rec(lli a, lli b, vector<vector<lli>>& dp){
	if(a == b) return 0;
	else if(dp[a][b] != -1) return dp[a][b];
	else{
		lli ans = 1e9;
		for(lli i=1; i<=a/2; i++){
			ans = min(ans, 1 + rec(i,b,dp) + rec(a-i,b,dp));
		}
		for(lli i=1; i<=b/2; i++){
			ans = min(ans, 1 + rec(a,i,dp) + rec(a,b-i,dp));
		}
		dp[a][b] = ans;
		return ans;
	}
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	lli a, b;
	cin >> a >> b;
	vector<vector<lli>> dp(a+1, vector<lli>(b+1, -1));
	cout << rec(a, b, dp);
	
	return 0;
	
	
}

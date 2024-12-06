#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int maxn = 1e6;
	vector<vector<lli>> dp(maxn+1, vector<lli>(2));
	dp[maxn][0] = dp[maxn][1] = 1ll;
	for(int i = maxn-1; i>=1; i--){
		dp[i][0] = (4*dp[i+1][0] + dp[i+1][1])%mod;
		dp[i][1] = (dp[i+1][0] + 2*dp[i+1][1])%mod;
	}
	
	int tt;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		lli ans = (dp[maxn-n+1][0] + dp[maxn-n+1][1])%mod;
		cout << ans << "\n";
	}
	
	return 0;
	
	
}

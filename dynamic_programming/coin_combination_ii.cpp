#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
  
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int mod = 1e9+7;
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0; i<n; i++) cin >> c[i];
	vector<int> dp(x+1);
	dp[0] = 1;
	for(int i=0; i<n; i++){
		for(int j=c[i]; j<=x; j++){
			dp[j] += dp[j-c[i]];
			dp[j] %= mod;
		}
	}
	cout << dp[x] ; 
	
	return 0;
	
	
}
	
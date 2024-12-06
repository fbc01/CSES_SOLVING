#include <iostream>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
lli power(lli x, lli y){
	if(y == 0) return 1ll;
	lli res = power(x, y/2);
	res *= res;
	if(y%2!=0) res *= x;
	res %= mod;
	return res;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	lli sum = (1ll * n * (n+1))/2;
	if(sum % 2 != 0){
		cout << 0 ;
		return 0;
	}
	lli tar = sum / 2;
	vector<lli> dp(tar+1);
	dp[0] = 1ll;
	for(int i=1; i<=n; i++){
		for(int j=tar; j>=i; j--){
			dp[j] += dp[j-i];
			dp[j] %= mod;
		}
	}
	dp[tar] *= power(2ll, mod-2);
	dp[tar] %= mod;
	cout << dp[tar];
	
	return 0;
	
	
}
	

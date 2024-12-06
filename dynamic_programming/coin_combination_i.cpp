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
	for(int i=1; i<=x; i++){
		for(int j=0; j<n; j++){
			if(i-c[j] >= 0){
				dp[i] += dp[i-c[j]];
				dp[i] %= mod;
			}
		}
	}
	cout << dp[x] ; 
	
	return 0;

}

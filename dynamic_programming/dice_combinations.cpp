#pragma GCC optimize("O3")
 
#include <iostream>
#include <vector>
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
	
	vector<int> dice = {1,2,3,4,5,6};
	int n;
	cin >> n;
	vector<lli> dp(n+1, 0ll);
	dp[0] = 1ll;
	for(int i=1; i<=n; i++){
		for(int j=0; j<6; j++){
			if(i-dice[j] >= 0) {
				dp[i] += dp[i-dice[j]];
				dp[i] %= mod;
			}
		}
	}
	cout << dp[n] ;
	
	return 0;
}
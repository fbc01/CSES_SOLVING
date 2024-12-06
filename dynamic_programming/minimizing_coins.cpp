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
	
	int n, x;
	cin >> n >> x;
	vector<int> c(n);
	for(int i=0; i<n; i++) cin >> c[i];
	vector<int> dp(x+1, 1e9);
	dp[0] = 0;
	for(int i=1; i<=x; i++){
		for(int j=0; j<n; j++){
			if(i-c[j] >= 0 && dp[i-c[j]] != 1e9){
				dp[i] = min(dp[i], 1+dp[i-c[j]]);
			}
		}
	}
	cout << (dp[x]==1e9?-1:dp[x]);
	
	return 0;
}
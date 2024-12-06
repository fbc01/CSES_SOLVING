#include <iostream>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	
	vector<vector<lli>> dp(n, vector<lli>(n,0));
	for(int i=0; i<n; i++) dp[i][i] = x[i];
	for(int i=0; i<n-1; i++) dp[i][i+1] = max(x[i], x[i+1]);
	for(int k=3; k<=n; k++){
		for(int i=0; i+k-1<n; i++){
			int j = i+k-1;
			dp[i][j] = max(x[i] + min(dp[i+2][j], dp[i+1][j-1]), x[j] + min(dp[i][j-2], dp[i+1][j-1]));
		}
	}
	cout << dp[0][n-1] ;
	
	
	return 0;
	
	
}

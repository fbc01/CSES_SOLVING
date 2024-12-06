#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
  
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	vector<int> h(n), s(n);
	for(int i=0; i<n; i++) cin >> h[i];
	for(int i=0; i<n; i++) cin >> s[i];
	vector<int> dp(x+1);
	for(int i=0; i<n; i++){
		for(int j=x; j>=1; j--){
			if(j>=h[i]){
				dp[j] = max(dp[j], s[i]+dp[j-h[i]]);
			}
		}
	}
	int ans = 0;
	for(int j=1; j<=x; j++) ans = max(ans, dp[j]);
	cout << ans;
	
	return 0;
	
	
}
	
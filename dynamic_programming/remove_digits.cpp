#include <iostream>
#include <set>
using namespace std;
#define lli long long int
  
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> dp(n+1, 1e9);
	dp[0] = 0;
	for(int i=1; i<=n; i++){
		set<int> st;
		int temp = i;
		while(temp != 0){
			st.insert(temp % 10);
			temp /= 10;
		}
		for(int j : st) dp[i] = min(dp[i], 1+dp[i-j]);
	}
	cout << dp[n] ;
	
	return 0;
	
	
}

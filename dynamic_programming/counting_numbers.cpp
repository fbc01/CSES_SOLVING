#include <iostream>
#include <assert.h>
using namespace std;
#define lli long long int
#define ull unsigned long long int
  
lli mod = 1e9+7;  
  
lli fun(int index, string& s, int prev, bool notzero, bool flag, vector<vector<vector<vector<lli>>>>& dp){
	if(index == s.size()) return 1ll;
	else if(index == 0){
		lli ans = 0;
		int digit = s[index]-'0';
		ans += fun(index+1, s, 0, false, true, dp);
		for(int i=1; i<digit; i++) ans += fun(index+1, s, i, true, true, dp);
		ans += fun(index+1, s, digit, true, false, dp);	
		return ans;
	}
	else if(dp[index][prev][(!notzero)][(!flag)] != -1) return dp[index][prev][(!notzero)][(!flag)];	
	else{
		if(notzero){
			//prev is checked even if it is 0
			if(flag){
				lli ans = 0;
				for(int i=0; i<=9; i++){
					if(i != prev) ans += fun(index+1, s, i, true, true, dp);
				}
				dp[index][prev][0][0] = ans;
				return ans;
			}
			else{
				lli ans = 0;
				int digit = s[index]-'0';
				for(int i=0; i<digit; i++){
					if(i != prev) ans += fun(index+1, s, i, true, true, dp);
				}
				if(digit != prev) ans += fun(index+1, s, digit, true, false, dp);
				dp[index][prev][0][1] = ans;
				return ans;
			}
		}
		else {
			//prev is ignored when it is 0 and cur is 0
			assert(prev == 0);
			if(flag){
				lli ans = 0;
				ans += fun(index+1, s, 0, false, true, dp);
				for(int i=1; i<=9; i++) ans += fun(index+1, s, i, true, true, dp);
				dp[index][prev][1][0] = ans;
				return ans;
			}
			else {
				lli ans = 0;
				int digit = s[index]-'0';
				if(digit == 0){
					ans += fun(index+1, s, 0, false, false, dp);
				}
				else {
					ans += fun(index+1, s, 0, false, true, dp);
					for(int i=1; i<digit; i++) ans += fun(index+1, s, i, true, true, dp);
					ans += fun(index+1, s, digit, true, false, dp);
				}
				dp[index][prev][1][1] = ans;
				return ans;
			}
		}
	}
}  
  
lli rec(ull x){
	if(x == 0) return 1ll;
	string n = to_string(x);
	vector<vector<vector<vector<lli>>>> dp(n.size(), vector<vector<vector<lli>>>(10, vector<vector<lli>>(2, vector<lli>(2,-1))));
	lli ans = fun(0, n, 0, false, false, dp);
	return ans;
}  
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ull a, b;
	cin >> a >> b;
	if(a == 0) cout << rec(b);
	else cout << rec(b)-rec(a-1);
	
	return 0;
	
	
}

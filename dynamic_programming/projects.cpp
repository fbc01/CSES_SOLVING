#include <iostream>
using namespace std;
#define lli long long int
  
lli mod = 1e9+7;  
  
 
lli rec(int i, vector<tuple<lli,lli,lli>>& v, vector<lli>& dp){
	if(i == v.size()) return 0;
	else if(dp[i] != -1) return dp[i];
	else {
		lli ans1 = rec(i+1, v, dp);
		lli ans2 = get<2>(v[i]);
		lli nexttime = get<1>(v[i]) + 1;
		lli l = i+1;
		lli r = v.size()-1;
		int in = -1;
		while(l<=r){
			lli mid = l + (r-l)/2;
			if(get<0>(v[mid]) < nexttime) l = mid+1;
			else {
				in = mid;
				r = mid-1;
			}
		}
		if(in != -1) ans2 += rec(in, v, dp);
		lli ans = max(ans1, ans2);
		dp[i] = ans;
		return ans;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<tuple<lli,lli,lli>> v(n);
	for(int i=0; i<n; i++){
		lli a, b, p;
		cin >> a >> b >> p;
		v[i] = make_tuple(a, b, p);
	}
	sort(v.begin(), v.end());
	vector<lli> dp(n, -1);
	cout << rec(0, v, dp);
	
	return 0;
	
	
}

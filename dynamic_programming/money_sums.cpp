#include <iostream>
#include <algorithm>
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
	sort(x.begin(), x.end());
	int sum = 0;
	for(int i=0; i<n; i++) sum += x[i];
	
	vector<int> v;
	vector<bool> dp(sum+1, false);
	dp[0] = true;
	for(int i=0; i<n; i++){
		for(int j=sum; j>=1; j--){
			if(j-x[i]>=0) dp[j] = dp[j] || dp[j-x[i]];
		}
	}
	for(int j=1; j<=sum; j++){
		if(dp[j]) v.push_back(j);
	}
	cout << v.size() << "\n";
	for(int j=0; j<v.size(); j++) cout << v[j] << " ";
	
	
	
	
	return 0;
	
	
}

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	long ans = 0;
	for(int i=0; i<n; i++){
		if(ans+1 < a[i]) break;
		else ans += a[i];
	}	
	cout << ans + 1;
	
	return 0;
}
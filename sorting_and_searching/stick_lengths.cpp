#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
ll mod = 1e9+7;
 
 
 
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a.begin(), a.end());
	ll sum = 0;
	for(int i=0; i<n; i++) sum += a[i];
	ll minv = 1e15;
	ll left = 0;
	for(int i=0; i<n; i++){
		ll lc = i;
		ll rc = n-i-1;
		ll right = sum - a[i] - left;
		ll cost = lc*a[i] - left;
		cost += right - rc*a[i];
		minv = min(minv, cost);
		left += a[i]; 
	}
	cout << minv;
	
	return 0;
}
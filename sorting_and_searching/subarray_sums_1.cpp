#include<iostream>
#include<map>
#include<vector>
using namespace std;
#define ll long long 
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	for(ll i=0; i<n; i++) cin >> a[i];
	ll ans = 0;
	map<ll,ll> mp;
	ll sum = 0;
	for(ll i=0; i<n; i++){
		sum += a[i];
		if(sum == x) ans++;
		else if(mp.find(sum-x) != mp.end()){
			ans += mp[sum-x];
		}
		mp[sum]++;
	}
	cout << ans;
	
	return 0;
}
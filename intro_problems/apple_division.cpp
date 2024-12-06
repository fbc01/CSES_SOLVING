#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
void rec(ll i, vector<ll>& p, vector<ll>& arr1, vector<ll>& arr2, ll& ans){
	if(i == (int)p.size()){
		ll s1 = 0;
		ll s2 = 0;
		for(ll &x: arr1) s1 += x;
		for(ll &y: arr2) s2 += y;
		ans = min(ans, abs(s1-s2));
	}
	else {
		arr1.push_back(p[i]);
		rec(i+1, p, arr1, arr2, ans);
		arr1.pop_back();
		arr2.push_back(p[i]);
		rec(i+1, p, arr1, arr2, ans);
		arr2.pop_back();
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin >> n;
	vector<ll> p(n);
	for(ll &x : p) cin >> x;
	
	vector<ll> arr1, arr2;
	
	ll ans = 1e12;
	rec(0, p, arr1, arr2, ans);
	
	cout << ans ;
		
	return 0;
}
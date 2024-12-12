#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define ll long long
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	
	int n, a, b;
	cin >> n >> a >> b;
	vector<ll> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	for(int i=1; i<n; i++) v[i] += v[i-1];
	multiset<ll> mt;
	for(int i=a-1; i<=b-1; i++) mt.insert(v[i]);
	ll ans = -1e15;
	
	for(int i=0; i+a-1<n; i++){
		ll p = (i-1>=0?v[i-1]:0);
		ll sum = *mt.rbegin();
		sum -= p;
		ans = max(ans, sum);
		mt.erase(mt.find(v[i+a-1]));
		if(i+b<n) mt.insert(v[i+b]);
	}
	cout << ans;
	
	return 0;
}
#include <iostream>
using namespace std;
#define ll long long
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	ll sum = 0;
	for(ll i=1; i<n; i++) {
		ll t; cin >> t;
		sum += t;
	}
	
	ll org = (n * (n+1))/2;
	
	cout << org - sum ;
	
	
		
	return 0;
}
 

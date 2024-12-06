#include <iostream>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	ll ans = 1;
	while(n--){
		ans *= 2;
		ans %= mod;
	}
	
	cout << ans ;
		
	return 0;
}

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
	
	ll c = 0;
	for(ll i = 5; i <= n; i *= 5){
		c += n/i;
	}
	cout << c ;	
		
	return 0;
}

#include <iostream>
using namespace std;
#define ll long long
 
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll k;
	cin >> k;
	for(ll i=1; i<=k; i++){
		ll squares = i * i;
		ll ways = (squares * (squares - 1))/2;
		ll notallowed = 4*(i-2)*(i-1);
		ll allowed = ways - notallowed;
		cout << allowed << "\n"; 
	}
		
	return 0;
}
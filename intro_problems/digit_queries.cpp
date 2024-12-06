/*****
 
	constructive
	>> took idea from -> https://codereview.stackexchange.com/questions/256773/digit-queries-cses-solution-giving-tle
 
*****/
 
 
#include <iostream>
using namespace std;
#define ll unsigned long long
 
ll power(ll x, ll y){
	if(y == 0) return 1ll;
	ll r = power(x, y/2);
	r *= r;
	if(y%2!=0) r *= x;
	return r;
}
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt;
	cin >> tt;
	while(tt--){
		
		ll k;
		cin >> k;
		
		int length = 1;
		ll count = 9ll * power(10, length-1) * length;
		
		while(k > count){
			k -= count;
			length++;
			count = 9ll * power(10, length-1) * length;
		}
		
		ll q = (k-1)/length;
		ll r = (k-1)%length;
		
		ll number = power(10ll , (length-1)) + q;
		string s = to_string(number);
		cout << s[r] << "\n";
		
	}
	
	return 0;
}

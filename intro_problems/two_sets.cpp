#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	ll sum = (n * (n+1))/2;
	
	if(sum % 2 != 0){
		cout << "NO";
		return 0;
	}
	
	cout << "YES" << endl;
	ll target = sum / 2;
	
	vector<ll> arr1, arr2;
	for(ll i = n; i>=1; i--){
		if(target-i >= 0){
			arr1.push_back(i);
			target -= i;
		}
		else {
			arr2.push_back(i);
		}
	}
	
	cout << arr1.size() << endl;
	for(ll &x : arr1) cout << x << " ";
	cout << endl;
	cout << arr2.size() << endl;
	for(ll &y : arr2) cout << y << " ";
	
		
	return 0;
}
 

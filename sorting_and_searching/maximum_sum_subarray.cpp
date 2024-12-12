#include<iostream>
#include<vector>
using namespace std;
#define ll long long
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<ll> arr(n);
	for(ll &a: arr) cin >> a;
	
	ll maxsum = -1e9;
	ll sum = 0;
	
	for(int i=0; i<n; i++){
		sum = max(sum + arr[i], arr[i]);
		maxsum = max(maxsum, sum);
	}
	cout << maxsum;
	
	return 0;
}
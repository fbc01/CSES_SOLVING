#pragma GCC optimize("O3")
 
#include <iostream>
#include <vector>
using namespace std;
#define lli long long int
#define pb push_back
#define mpr make_pair
#define ld long double
#define pll pair<lli,lli>
#define fi first
#define se second
 
lli mod = 1e9 + 7;
 
 
int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> v;
	for(int i=0; i<n; i++){
		if(v.empty() || v.back() < a[i]) v.push_back(a[i]);
		else {
			int index = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
			v[index] = a[i];
		}
	}
	cout << v.size();
	
	
	return 0;
}

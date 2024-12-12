#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
#define lli long long int
#define ull unsigned long long int
#define pb push_back
#define mpr make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<lli> arr(n);
	for(int i=0; i<n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	lli ans = max(2*arr.back(), accumulate(arr.begin(), arr.end(), 0ll));
	cout << ans;
	
	return 0;
}

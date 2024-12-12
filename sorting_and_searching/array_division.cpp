#include<iostream>
#include<vector>
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
	
	lli n, k;
	cin >> n >> k;
	vector<lli> a(n);
	for(lli &e: a) cin >> e;
	
	lli sum = 0, maxv = 0;
	for(lli &e: a){
		sum += e;
		maxv = max(maxv, e);
	}
	
	lli left = maxv;
	lli right = sum;
	
	lli ans = 1e12;
	
	while(left <= right){
		lli mid = left + (right-left)/2;
		sum = 0;
		lli count = 1;
		for(lli &e: a){
			if(sum + e <= mid) sum += e;
			else {
				count++;
				sum = e;
			}
		}
		if(count <= k) {
			ans = mid;
			right = mid-1;
		}
		else left = mid+1;
	}
	
	cout << ans;
	
	return 0;
}
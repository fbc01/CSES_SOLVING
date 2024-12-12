#include<iostream>
#include<vector>
#include<map>
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
	vector<lli> arr(n);
	for(lli &a: arr) cin >> a;
	
	lli prev = 0;
	map<lli,lli> mp;
	lli ans = 0;
	vector<pair<lli,lli>> vec;
	for(lli i=0; i<=n; i++){
		if(i==n){
			vec.push_back({prev, i-1});
		}
		else {
			mp[arr[i]]++;
			if(mp.size()>k){
				vec.push_back({prev, i-1});
				while(mp.size()>k){
					mp[arr[prev]]--;
					if(mp[arr[prev]] == 0) mp.erase(mp.find(arr[prev]));
					prev++;
				}
			}
		}
	}
	
	for(lli i=0; i<vec.size(); i++){
		lli len = vec[i].second-vec[i].first+1;
		ans += (len * (len+1))/2;
	}
	for(lli i=1; i<vec.size(); i++){
		lli len = vec[i-1].second - vec[i].first+1;
		if(len > 0) ans -= (len * (len+1))/2;
	}
	cout << ans;
	
	return 0;
}

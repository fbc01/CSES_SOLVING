#include<iostream>
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
	vector<pii> vec(n);
	for(int i=0; i<n; i++){
		int x; cin >> x;
		vec[i] = {x, i};
	}
	sort(vec.begin(), vec.end());
	int ans = 1;
	for(int i=1; i<n; i++){
		if(vec[i].second < vec[i-1].second) ans++;
	}
	cout << ans;
	
	return 0;
}

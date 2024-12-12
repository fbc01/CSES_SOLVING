#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll unsigned long long
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	
	vector<int> p(n);
	for(int &e: p) cin >> e;
	
	
	sort(p.begin(), p.end());
	
	int l = 0, r = n-1;
	int ans = 0;
	
	while(l <= r){
		if(l == r) {
			ans++;
			l++;
		}
		else if(p[l]+p[r] <= x){
			ans++;
			l++;
			r--;
		}
		else {
			ans++;
			r--;
		}
	}
	
	cout << ans;
	
	return 0;
}
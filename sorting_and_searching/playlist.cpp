#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define ll long long 
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	set<int> st;
	int l = 0;
	st.insert(a[l]);
	int r = l;
	int ans = 1;
	while(l<n && r < n){
		while(r+1 < n && st.find(a[r+1]) == st.end()){
			st.insert(a[r+1]);
			r++;
			ans = max(ans, r-l+1);
		}
		st.erase(st.find(a[l]));
		l++;
	}
	cout << ans;

	return 0;
}
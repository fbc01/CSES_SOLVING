#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
 
bool comp(pair<int,int>& p1, pair<int,int>& p2){
	if(p1.second < p2.second) return true;
	else if(p1.second > p2.second) return false;
	else return p1.first < p2.first;
} 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	
	int n, k;
	cin >> n >> k;
	set<pair<int,int>> st;
	for(int i=1; i<=k; i++) st.insert({0, i});
	
	vector<pair<int,int>> v(n);
	for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), comp);
	
	int ans = 0;
	for(pair<int,int> p: v){
		int a = p.first;
		int d = p.second;
		auto it = st.upper_bound({a,k});
		if(it == st.begin()) continue;
		it = prev(it);
		pair<int,int> f = *it;
		st.erase(it);
		st.insert({d, f.second});
		ans++;
	}
	cout << ans;
	
	return 0;
}

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define ll unsigned long long
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> a(n);
	for(int &e: a) cin >> e;
	
	vector<int> b(m);
	for(int &f: b) cin >> f;
	
	multiset<int> ms;
	for(int &f: b) ms.insert(f);
	
	sort(a.begin(), a.end());
	
	int ans = 0;
	for(int &e : a){
		auto itr = ms.lower_bound(e-k);
		if(itr != ms.end() && (*itr) <= e + k){
			ans++;
			ms.erase(itr);
		}
	}
	
	cout << ans;
	
	
	return 0;
}

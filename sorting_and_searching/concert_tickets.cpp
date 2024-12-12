#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	multiset<int> mt;
	for(int i=0; i<n; i++){
		int h;
		cin >> h;
		mt.insert(h);
	}
	vector<int> ans;
	for(int i=0; i<m; i++){
		int t;
		cin >> t;
		if(mt.empty()) ans.push_back(-1);
		else {
			auto itr = mt.upper_bound(t);
			if(itr == mt.begin()) ans.push_back(-1);
			else {
				itr = prev(itr);
				ans.push_back(*itr);
				mt.erase(itr);
			}
		}
	}
	for(int i=0; i<m; i++) cout << ans[i] << "\n";
	
	return 0;
}
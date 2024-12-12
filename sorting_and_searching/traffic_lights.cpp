#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define ll long long 
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int x, n;
	cin >> x >> n;
	set<int> st;
	st.insert(0);
	st.insert(x);
	multiset<int> st2;
	st2.insert(x);
	vector<int> ans;
	for(int i=0; i<n; i++){
		int p;
		cin >> p;
		auto right = st.upper_bound(p);
		auto left = prev(right);
		int lm = *left;
		int rm = *right;
		st2.erase(st2.find(rm-lm));
		st2.insert(p-lm);
		st2.insert(rm-p);
		st.insert(p);
		ans.push_back(*(st2.rbegin()));
	}
	for(int e : ans) cout << e << " ";

	return 0;
}
#include<iostream>
#include<set>
#include<vector>
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
	multiset<int> st;
	for(int i=0; i<n; i++){
		auto it = st.upper_bound(a[i]);
		if(it != st.end()) st.erase(it);
		st.insert(a[i]); 
	}
	cout << st.size();

	return 0;
}
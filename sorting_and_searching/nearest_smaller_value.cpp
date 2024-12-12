#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define ll long long 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	vector<int> ans(n, -1);
	stack<int> st;
	for(int i=0; i<n; i++){
		if(st.empty()) st.push(i);
		else {
			while(!st.empty() && a[st.top()] >= a[i]) st.pop();
			if(!st.empty()) ans[i] = st.top();
			st.push(i);
		}
	}
	for(int i=0; i<n; i++) cout << ans[i]+1 << " ";
	
	
	return 0;
}
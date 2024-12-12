#include<iostream>
#include<set>
using namespace std;
#define ll unsigned long long
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	set<int> st;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		st.insert(x);
	}
	cout << st.size() ;
	
	return 0;
}

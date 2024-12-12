#include<iostream>
#include<set>
#include<vector>
using namespace std;
#define ll long long 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	multiset<int> st1, st2;
	for(int i=0; i<k-1; i++){
		st2.insert(a[i]);
		if(st2.size() > k/2){
			st1.insert(*(st2.begin()));
			st2.erase(st2.begin());
		}
	}
	vector<int> p;
	for(int i=k-1; i<n; i++){
		st2.insert(a[i]);
		if(st2.size() > k/2){
			st1.insert(*(st2.begin()));
			st2.erase(st2.begin());
		}
		p.push_back((*(st1.rbegin())));
		if(st2.find(a[i-k+1]) != st2.end()){
			st2.erase(st2.find(a[i-k+1]));
			st2.insert(*st1.rbegin());
			st1.erase(prev(st1.end()));
		}
		else st1.erase(st1.find(a[i-k+1]));
	}
	
	for(int v : p) cout << v << " ";
	
	
	return 0;
}
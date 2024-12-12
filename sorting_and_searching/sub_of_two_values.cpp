#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll unsigned long long
#define pii pair<int,int> 
#define make_pair mpr
vector<pii> p;
int n;
int x;
 
int bs(int i){
	int l = i+1;
	int r = n-1;
	int t = x - p[i].first;
	
	while(l <= r){
		int m = (l + r)/2;
		if(p[m].first == t) return m;
		else if(p[m].first < t) l = m+1;
		else r = m-1;
	}
	return -1;
} 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> x;
	
	p.resize(n);
	for(int i=0; i<n; i++){
		int e;
		cin >> e;
		p[i] = {e, i};
	}
	
	
	sort(p.begin(), p.end());
	
	for(int i=0; i < n; i++){
		int j = bs(i);
		if(j != -1){
			cout << p[i].second+1 << " " << p[j].second+1 ;
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE";
	
	return 0;
}

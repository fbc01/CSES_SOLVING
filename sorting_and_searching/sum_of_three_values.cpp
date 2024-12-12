#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long 
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	vector<pair<int,int>> a(n);
	for(int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			int sum = a[i].first + a[j].first;
			int tar = x - sum;
			int k = -1;
			int l = j+1, r = n-1;
			while(l <= r){
				int m = (l+r)/2;
				if(a[m].first == tar) {
					k = m;
					break;
				}
				else if(a[m].first < tar) l = m+1;
				else r = m-1;
			}
			if(k != -1) {
				cout << a[i].second+1 << " " << a[j].second+1 << " " << a[k].second+1 ;
				return 0;
			}
		}
	}
	
	cout << "IMPOSSIBLE";

	return 0;
}
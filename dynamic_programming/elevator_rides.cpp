#include<iostream>
using namespace std;
#define lli long long int
#define pii pair<int,int>
#define mpr make_pair
lli mod = 1e9 + 7;
 
pii min(pii& a, pii& b){
	if(a.first < b.first) return a;
	else if(a.first > b.first) return b;
	else {
		if(a.second <= b.second) return a;
		else return b;
	} 
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for(int i=0; i<n; i++) cin >> a[i];
	pii best[1<<n];
	best[0] = mpr(1,0);
	for(int s=1; s<(1<<n); s++){
		best[s] = mpr(n+1,0);
		for(int p=0; p<n; p++){
			if((s&(1<<p))){
				pii option = best[s^(1<<p)];
				if(option.second + a[p] <= x){
					option.second += a[p];
				}
				else {
					option.first++;
					option.second = min(a[p], option.second);
				}
				best[s] = min(best[s], option);
			}
		}
	}
	cout << best[(1<<n)-1].first;

	return 0;
}
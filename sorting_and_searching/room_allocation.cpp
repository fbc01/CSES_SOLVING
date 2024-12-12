#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
#define lli long long int
#define ull unsigned long long int
#define pb push_back
#define mpr make_pair
#define pii pair<int,int>
#define pll pair<lli,lli>
#define ld long double
 
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	int n;
	cin >> n;
	vector<pii> in(n), out(n);
	set<int> free;
	for(int i=0; i<n; i++){
		cin >> in[i].first >> out[i].first;
		in[i].second = out[i].second = i;
		free.insert(i);
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	vector<int> ans(n);
	for(int i=0,j=0; i<n; i++){
		while(j<n && out[j].first < in[i].first){
			free.insert(ans[out[j].second]);
			j++;
		}
		ans[in[i].second] = *free.begin();
		free.erase(free.begin());
	}
	int num = 0;
	for(int i=0; i<n; i++) num = max(num, ans[i]);
	cout << num+1 << "\n";
	for(int i=0; i<n; i++) cout << ans[i]+1 << " ";
	
	return 0;
}
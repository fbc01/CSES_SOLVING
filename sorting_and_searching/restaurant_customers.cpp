#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<pair<int,int>> vec;
	for(int i=0; i<n; i++){
		int a, b;
		cin >> a >> b;
		vec.emplace_back(a, 1);
		vec.emplace_back(b+1, -1);
	}
	sort(vec.begin(), vec.end());
	int maxv = 0;
	int cur = 0;
	for(int i=0; i<vec.size(); i++){
		cur += vec[i].second;
		maxv = max(maxv, cur);
	}
	cout << maxv;
	
	
	return 0;
}
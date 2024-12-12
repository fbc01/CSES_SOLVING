#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
 
bool comp(pair<int,int>& p1, pair<int,int>& p2){
	if(p1.second < p2.second) return true;
	else if(p1.second > p2.second) return false;
	else return p1.first <= p2.first;
} 
 
//manual comparison gives tle in one case
 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<pair<int,int>> v(n);
	for(int i=0; i<n; i++) cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	int prev = 0;
	int count = 0;
	for(int i=0; i<n; i++){
		if(v[i].second >= prev){
			//greedy selection, we know we will end fastest
			count++;
			prev = v[i].first;
		}
	}
	cout << count;
	
	return 0;
}
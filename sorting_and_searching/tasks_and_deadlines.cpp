#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 
 
bool comp(pair<ll,ll>& p1, pair<ll,ll>& p2){
	if(p1.first < p2.first) return true;
	else if(p1.first > p2.first) return false;
	else return p1.second < p2.second;
} 
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll n;
	cin >> n;
	vector<pair<ll,ll>> v(n);
	for(ll i=0; i<n; i++) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), comp);
	ll time = 0;
	ll profit = 0;
	for(ll i=0; i<n; i++){
		time += v[i].first;
		profit += v[i].second - time;
	}
	cout << profit;
	
	return 0;
}
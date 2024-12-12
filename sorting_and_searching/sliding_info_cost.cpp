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
	for(int &e: a) cin >> e;
	multiset<int> st1, st2;
	
	ll sum1 = 0, sum2 = 0;
	for(int i=0; i<k-1; i++) {
		sum2 += a[i];
		st2.insert(a[i]);
		if(st2.size() > k/2){
			sum2 -= *st2.begin();
			sum1 += *st2.begin();
			st1.insert(*st2.begin());
			st2.erase(st2.begin());
		}
	} 
	  
	for(int i=k-1; i<n; i++){
		sum2 += a[i];
		st2.insert(a[i]);
		if(st2.size()>k/2){
			sum2 -= *st2.begin();
			sum1 += *st2.begin();
			st1.insert(*st2.begin());
			st2.erase(st2.begin());
		}
		if(k%2 == 0){
			ll s1 = 0, s2 = 0;
			s1 += st1.size() * (*st1.rbegin()) - sum1;
			s1 += sum2 - st2.size() * (*st1.rbegin());
			s2 += st1.size() * (*st2.begin()) - sum1;
			s2 += sum2 - st2.size() * (*st2.begin());
			ll sum = min(s1, s2);
			cout << sum << " ";
		}
		else {
			ll sum = 0;
			sum += st1.size() * (*st1.rbegin()) - sum1;
			sum += sum2 - st2.size() * (*st1.rbegin());
			cout << sum << " ";
		}
		if(st2.find(a[i-k+1]) != st2.end()){
			sum2 -= a[i-k+1];
			st2.erase(st2.find(a[i-k+1]));
			sum1 -= *st1.rbegin();
			sum2 += *st1.rbegin();
			st2.insert(*st1.rbegin());
			st1.erase(prev(st1.end()));
		}
		else {
			sum1 -= a[i-k+1];
			st1.erase(st1.find(a[i-k+1]));
		}
	}
	
	
	return 0;
}

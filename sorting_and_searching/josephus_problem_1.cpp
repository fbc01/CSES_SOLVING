#include<iostream>
#include<queue>
#include<set>
#include<vector>
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
	queue<int> q;
	for(int i=1; i<=n; i++) q.push(i);
	while(q.size() != 1){
		q.push(q.front());
		q.pop();
		cout << q.front() << " ";
		q.pop();
	} 
	cout << q.front();

	return 0;
}
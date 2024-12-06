#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> x(n);
	for(int i=0; i<n; i++) cin >> x[i];
	ll sum = 0;
	for(int i=1; i<n; i++){
		if(x[i] >= x[i-1]) continue;
		else {
			sum += x[i-1]-x[i];
			x[i] = x[i-1];
		}
	}
	cout << sum;
		
	return 0;
}

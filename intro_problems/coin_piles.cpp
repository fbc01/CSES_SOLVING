#include <iostream>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt;
	cin >> tt;
	while(tt--){
		int a, b;
		cin >> a >> b;
		int total = a+b;
		if(total % 3 != 0){
			cout << "NO" << endl;
		}
		else {
			int step = total / 3;
			if(step <= a && step <= b){
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		 
	}	
		
	return 0;
}

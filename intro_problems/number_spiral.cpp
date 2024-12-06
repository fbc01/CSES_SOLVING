#include <iostream>
using namespace std;
#define ll unsigned long long
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tt;
	cin >> tt;
	while(tt--){
		ll row, col;
		cin >> row >> col;
	
		if(row == col){
			ll ans = row * row - row + 1;
			cout << ans;
		}
		else if(row > col){
			ll start = 1 + (row-1)*(row-1);
			ll end = row*row;
			if(row % 2 != 0){
				ll ans = start + col-1;
				cout << ans;
			}
			else {
				ll ans = end - col + 1;
				cout << ans;
			}
		}
		else {
			ll start = 1 + (col-1)*(col-1);
			ll end = col * col;
			if(col % 2 == 0){
				ll ans = start + row-1;
				cout << ans;
			}
			else {
				ll ans = end - row + 1;
				cout << ans;
			}
		}
		cout << "\n";
	}
	
	
	
		
	return 0;
}

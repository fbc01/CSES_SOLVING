#include <iostream>
using namespace std;
#define ll long long
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	
	int ans = 1;
	
	int p = 0;
	for(int i=1; i<(int)s.size(); i++){
		if(s[p] == s[i]){
			ans = max(i-p+1, ans);
		}
		else {
			p = i;
		}
	}
	
	cout << ans;
	
		
	return 0;
}

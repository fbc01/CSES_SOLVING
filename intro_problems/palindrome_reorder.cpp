#include <iostream>
#include <vector>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
 
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;
	cin >> s;
	vector<int> f(26);
	for(char c: s) f[c-'A']++;
	bool flag = true;
	for(int i=0; i<26; i++){
		if(f[i]%2!=0){
			if(!flag){
				cout << "NO SOLUTION";
				return 0;
			}
			else {
				flag = false;
			}
		}
	}
	string res = "";
	for(int i=0; i<26; i++){
		if(f[i]%2==0){
			int t = f[i]/2;
			while(t--){
				res += (char)('A'+i);
			}
		}
	}
	for(int i=25; i>=0; i--){
		if(f[i]%2 != 0){
			int t = f[i];
			while(t--){
				res += (char)('A'+i);
			}
		}
	}
	for(int i=25; i>=0; i--){
		if(f[i]%2==0){
			int t = f[i]/2;
			while(t--){
				res += (char)('A'+i);
			}
		}
	}
	cout << res;
		
	return 0;
}

#include <iostream>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for (int i = 0; i < (1 << n); i++)
    {
        int val = (i ^ (i >> 1));
         
        bitset<32> r(val);
         
        string s = r.to_string();
        cout << s.substr(32 - n) << endl;
    }
		
	return 0;
}

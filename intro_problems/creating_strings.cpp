#include <iostream>
#include <algorithm>
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
	vector<string> vec;
	sort(s.begin(), s.end());
	do {
		vec.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	
	cout << vec.size() << endl;
	for(string &ss : vec) cout << ss << endl;
	
		
	return 0;
}

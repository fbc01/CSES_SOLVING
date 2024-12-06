#include <iostream>
using namespace std;
#define ll long long
ll mod = 1e9 + 7;
 
 
 
 
void toh(int n, int first, int second, int third, vector<pair<int,int>>& vec){
	if(n == 1){
		vec.push_back({first, third});
	}
	else {
		toh(n-1, first, third, second, vec);
		vec.push_back({first, third});
		toh(n-1, second, first, third, vec);
	}
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<pair<int,int>> vec;
	
	toh(n, 1, 2, 3, vec);
	
	cout << vec.size() << endl;
	for(pair<int,int>& p : vec){
		cout << p.first << " " << p.second << endl;
	}
	
	return 0;
}

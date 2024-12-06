#include <iostream>
#include <vector>
using namespace std;
#define ll long long
 
ll ans = 0;
vector<string> arr(8);
 
bool possible(int x, int y){
	if(arr[x][y] == '*') return false;
	int tx = x;
	int ty = y;
	while(tx > 0){
		tx--;
		if(arr[tx][ty] == 'Q') return false;
	}
	tx = x; ty = y;
	while(tx > 0 && ty > 0){
		tx--; ty--;
		if(arr[tx][ty] == 'Q') return false;
	}
	tx = x; ty = y;
	while(tx > 0 && ty < 7){
		tx--; ty++;
		if(arr[tx][ty] == 'Q') return false; 
	}
	return true;
}
 
 
void bt(int i){
	if(i == 8) {
		ans++;
		return;	
	}
	for(int k=0; k<=7; k++){
		if(possible(i, k)){
			arr[i][k] = 'Q';
			bt(i+1);
			arr[i][k] = '.';
		}
	}
}
 
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
 
	for(int i=0; i<8; i++) cin >> arr[i];
	
	bt(0);
	
	cout << ans;
		
	return 0;
}

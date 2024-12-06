#include <iostream>
using namespace std;
#define lli long long int
lli mod = 1e9 + 7;
 
void generate_next_masks(int current_mask, int i, int next_mask, int n, vector<int>& next_masks){
    if(i == n + 1){
        next_masks.push_back(next_mask);
   	    return;
    }
      
    if((current_mask & (1 << i)) != 0){
        generate_next_masks(current_mask, i + 1, next_mask, n, next_masks);
  	}
    if(i != n){
      	if((current_mask & (1 << i)) == 0 && (current_mask & (1 << (i+1))) == 0){
      		generate_next_masks(current_mask, i + 2, next_mask, n, next_masks);	
		}
	}
        
    if((current_mask & (1 << i)) == 0){
		generate_next_masks(current_mask, i + 1, next_mask + (1 << i), n, next_masks);
	}    
}
 
lli rec(int col, int mask, int m, int n, vector<vector<lli>>& dp){
	if(col == m+1){
		if(mask == 0) return 1ll;
		else return 0ll;
	}
	else if(dp[col][mask] != -1) return dp[col][mask];
	else {
		lli ans = 0;
		vector<int> next_masks;
		generate_next_masks(mask, 1, 0, n, next_masks);
		
		for(int nm : next_masks){
			ans += rec(col+1, nm, m, n, dp);
			ans %= mod;
		}
		return dp[col][mask] = ans;
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vector<vector<lli>> dp(m+1, vector<lli>((1<<(n+1)) , -1));
	cout << rec(1, 0, m, n, dp);
	
	return 0;
}
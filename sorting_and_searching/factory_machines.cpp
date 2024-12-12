#include<iostream>
#include<vector>
using namespace std;
#define ll long long
 
bool possible(ll val, vector<ll>& a, ll t) {
    ll cur = 0;
    for (ll i : a) {
        cur += val / i;
        if (cur >= t) return true;
    } 
    return false;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll &i : a) cin >> i;
    
    ll low = 0;
    ll high = 1e18;
    
    ll ans = high;
    while (low <= high) {
        ll mid = low + (high-low)/2;
        if (possible(mid, a, t)) {
            ans = min(mid, ans);
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    
    cout << ans;
    
    return 0;
}

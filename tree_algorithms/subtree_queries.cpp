
#include<iostream>
using namespace std;
#define ll long long
 
ll n, q;
vector<ll> w;
vector<vector<ll>> g;
vector<ll> in, out;
ll timer = 0;
vector<ll> f;
 
ll getMid(ll s, ll e) { return s + (e -s)/2; }
 
void updateValueUtil(ll *st, ll ss, ll se, ll i, ll diff, ll si){
	if (i < ss || i > se) return;
	st[si] = st[si] + diff;
	if (se != ss){
		ll mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si + 2);
	}
}
 
void updateValue(vector<ll>& arr, ll *st, ll n, ll i, ll new_val){
	if (i < 0 || i > n-1){
		cout<<"Invalid Input";
		return;
	}
	ll diff = new_val - arr[i];
	arr[i] = new_val;
	updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
ll getSumUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll si){
	if (qs <= ss && qe >= se) return st[si];
	if (se < qs || ss > qe) return 0;
	ll mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}
 
ll getSum(ll *st, ll n, ll qs, ll qe){
	if (qs < 0 || qe > n-1 || qs > qe){
		cout<<"Invalid Input";
		return -1;
	}
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
ll constructSTUtil(vector<ll>& arr, ll ss, ll se, ll *st, ll si){
	if (ss == se){
		st[si] = arr[ss];
		return arr[ss];
	}
	ll mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, si*2+1) + constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}
 
ll *constructST(vector<ll>& arr, ll n){
	ll x = (ll)(ceil(log2(n)));
	ll max_size = 2*(ll)pow(2, x) - 1;
	ll *st = new ll[max_size];
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}
 
void dfs(ll s = 0, ll p = -1){
	in[s] = timer++;
	for(ll v: g[s]){
		if(v != p) dfs(v, s);
	}
	out[s] = timer++;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	cin >> n >> q;
	w.resize(n);
	for(ll& x: w) cin >> x;
	g.resize(n);
	for(ll i=0; i<n-1; i++){
		ll a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	in.resize(n);
	out.resize(n);
	dfs();
	f.resize(timer);
	for(ll i=0; i<n; i++){
		f[in[i]] = w[i];
		f[out[i]] = w[i];
	}
	
	ll* st = constructST(f, (ll)f.size());
	while(q--){
		ll t; cin >> t;
		if(t==1){
			ll s, x; cin >> s >> x; s--;
			updateValue(f, st, (ll)f.size(), in[s], x);
			updateValue(f, st, (ll)f.size(), out[s], x);
		}
		else {
			ll s; cin >> s; s--;
			ll res = getSum(st, (ll)f.size(), in[s], out[s]);
			res /= 2;
			cout << res << "\n";
		}
	}
	
	
	return 0;
}

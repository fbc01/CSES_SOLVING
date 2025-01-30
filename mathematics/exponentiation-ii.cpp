#include<iostream>
using namespace std;
const int mod = 1e9+7;

int power(int a, int b, int c) {
    if (b == 0) return 1;
    int ans = power(a, b/2, c);
    long long res = (1ll * ans * ans)%c;
    if (b%2) res = (res * a)%c;
    return (int)res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << power(a, power(b, c, mod-1), mod) << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
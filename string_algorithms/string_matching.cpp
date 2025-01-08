#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    string w = t + "$" + s;
    int n = w.size();
    int m = t.size();
    vector<int> lps(n, 0);
    int p = 0;
    for (int i=1; i<n; i++) {
        if (w[i] == w[p]) {
            lps[i] = ++p;
        } else if (p > 0) {
            p = lps[p-1];
            i--;
        } else {
            continue;
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        if (lps[i] == m) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    string w;
    cin >> w;
    int n = w.size();
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
    vector<int> ans;
    for (int i=n-1; i>=0;) {
        if (lps[i] > 0) {
            ans.push_back(lps[i]);
            i = lps[i]-1;
        } else {
            break;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) cout << i << " ";
    cout << "\n";

    return 0;
}
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long


class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd = false;
    int count = 0;

    TrieNode() {
        children = vector<TrieNode*>(26, nullptr);
    }
};

const int mod = 1e9+7;

void insert(TrieNode* root, string& s) {
    TrieNode* node = root;
    for (char c : s) {
        if (node->children[c-'a'] == nullptr) {
            node->children[c-'a'] = new TrieNode();
        }
        node = node->children[c-'a'];
    }
    node->isEnd = true;
    node->count++;
}

ll rec(int i, string& s, TrieNode* root, vector<ll>& dp) {
    int n = s.size();
    if (i == n) {
        return 1;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    TrieNode* node = root;
    ll ans = 0;
    int j = i;
    while (j < n && node->children[s[j]-'a'] != nullptr) {
        node = node->children[s[j]-'a'];
        if (node->isEnd) {
            ans = (ans + (node->count * rec(j+1, s, root, dp))%mod) % mod;
        }
        j++;
    }
    return dp[i] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;
    int k;
    cin >> k;
    TrieNode* root = new TrieNode();

    while (k--) {
        string t;
        cin >> t;
        insert(root, t);
    }

    int n = s.size();
    vector<ll> dp(n, -1);
    cout << rec(0, s, root, dp) << "\n";


    return 0;
}
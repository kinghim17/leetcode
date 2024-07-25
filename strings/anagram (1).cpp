#include <bits/stdc++.h>
#define ll long long
#define endl  "\n"
using namespace std;

bool solve(string &s1, string &s2) {
    ll n = s1.length();
    ll m = s2.length();
    if (m != n) {
        return false;
    }
    unordered_map<char, int> m1;
    for (ll i = 0; i < n; i++) {
        m1[s1[i]]++;
        m1[s2[i]]--;
    }
    for (auto &entry : m1) {
        if (entry.second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    int N;
    cin >> N;
    while (N--) {
        cin >> s1 >> s2;
        cout << (solve(s1, s2) ? "true" : "false") << endl;
    }

    return 0;
}

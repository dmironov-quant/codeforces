// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/C

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> zfn(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> nf(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            nf[i] = min(nf[i-l], r-i);
        }
        while (s[i+nf[i]] == s[nf[i]]) {
            ++nf[i];
        }
        if (i + nf[i] > r) {
            l = i;
            r = i + nf[i];
        }
    }
    return nf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        vector<int> z = zfn(s);
        vector<int> cnt(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            ++cnt[z[i]];
        }
        for (int i = n - 1; i >= 0; --i) {
            cnt[i] += cnt[i+1];
        }
        for (int i = 1; i < n + 1; ++i) {
            ++cnt[i];
        }
        for (int i = 1; i < n + 1; ++i) {
            cout << cnt[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}

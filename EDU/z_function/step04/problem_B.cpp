// https://codeforces.com/edu/course/2/lesson/3/4/practice/contest/272262/problem/B

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> z_function(const string& f) {
    int n = static_cast<int>(f.size());
    vector<int> nf(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            nf[i] = min(nf[i-l], r-i);
        }
        while (f[i+nf[i]] == f[nf[i]]) {
            ++nf[i];
        }
        if (i+nf[i] > r) {
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
        string s, t;
        cin >> s >> t;
        if (s == t) {
            cout << 0 << '\n';
            continue;
        }
        int n = static_cast<int>(s.size());
        string f = s + '#' + t + t;
        int k = static_cast<int>(f.size());
        vector<int> zfn = z_function(f);
        int shift = -1;
        for (int i = k - 1; i >= n + 1; --i) {
            if (zfn[i] == n) {
                shift = k - (i + (int)(t.size()));
                break;
            }
        }
        cout << shift << '\n';
    }
    
    return 0;
}

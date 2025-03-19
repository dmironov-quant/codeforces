// https://codeforces.com/edu/course/2/lesson/2/2/practice/contest/269103/problem/A

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void radix_sort(vector<pair<pair<int, int>, int>>& a) {
    int n = (int)a.size();

    {
        vector<int> cnt(n);
        for (const auto& x : a) {
            ++cnt[x.first.second];
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i-1] + cnt[i-1];
        }
        for (const auto& x : a) {
            int i = x.first.second;
            a_new[pos[i]] = x;
            ++pos[i];
        }
        a = a_new;
    }

    {
        vector<int> cnt(n);
        for (const auto& x : a) {
            ++cnt[x.first.first];
        }
        vector<pair<pair<int, int>, int>> a_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; ++i) {
            pos[i] = pos[i-1] + cnt[i-1];
        }
        for (const auto& x : a) {
            int i = x.first.first;
            a_new[pos[i]] = x;
            ++pos[i];
        }
        a = a_new;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += '$';

    int n = (int)s.size();

    vector<int> p(n), c(n);
    
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = { s[i], i };
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    // k -> k + 1
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = { { c[i], c[(i + (1 << k)) % n] }, i};
        }
        radix_sort(a);
        // sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        ++k;
     }

    for (int i = 0; i < n; ++i) {
        // cout << p[i] << ' ' << s.substr(p[i], n - p[i]) << '\n';
        cout << p[i] << ' ';
    }
    
    return 0;
}

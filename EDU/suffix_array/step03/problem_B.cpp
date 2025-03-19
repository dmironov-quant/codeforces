// https://codeforces.com/edu/course/2/lesson/2/3/practice/contest/269118/problem/B

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

    string t;
    cin >> t;
    t += '$';

    int n = (int)t.size();

    vector<int> p(n), c(n);
    
    {
        // k = 0
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = { t[i], i };
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

    int m;
    cin >> m;
    while (m--) {
        string s;
        cin >> s;
        int k = (int)s.size();
        int left = -1;
        int right = (int)t.size();
        while (right > left + 1) {
            int middle = left + (right - left) / 2;
            string d = t.substr(p[middle], k);
            if (d < s) {
                left = middle;
            }
            else {
                right = middle;
            }
        }
        int left_boundary = right;

        left = -1;
        right = (int)t.size();
        while (right > left + 1) {
            int middle = left + (right - left) / 2;
            string d = t.substr(p[middle], k);
            if (d <= s) {
                left = middle;
            } else {
                right = middle;
            }
        }
        int right_boundary = right;

        cout << right_boundary - left_boundary << '\n';
    }
    
    return 0;
}

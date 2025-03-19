// https://codeforces.com/edu/course/2/lesson/3/3/practice/contest/272263/problem/A

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


vector<int> z_function(const string& s) {
    int n = static_cast<int>(s.size());
    vector<int> zn(n, 0);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; ++i) {
        if (i < r) {
            zn[i] = min(zn[i-l], r-i);
        }
        while (s[i + zn[i]] == s[zn[i]]) {
            ++zn[i];
        }
        if (i + zn[i] > r) {
            l = i;
            r = i + zn[i];
        }
    }
    return zn;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<int> zn = z_function(s);

    for (size_t i = 0; i < zn.size(); ++i) {
        cout << zn[i] << ' ';
    }
    
    return 0;
}

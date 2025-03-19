// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/A

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool check(const string& s) {
    string t{s.rbegin(), s.rend()};
    return s == t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        size_t longest_palindrom = 0;
        string t = "";
        for (int i = 0; i < n; ++i) {
            t += s[i];
            bool is_palindrom = check(t);
            if (is_palindrom) {
                longest_palindrom = max(longest_palindrom, t.size());
            }
        }
        cout << longest_palindrom << '\n';
    }
    
    return 0;
}

// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/B

#include <iostream>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            string t = "";
            for (int j = i; j < n; ++j) {
                t += s[j];
                bool is_prefix = false;
                string x = "";
                for (int end_pos = 0; end_pos < n; ++end_pos) {
                    x += s[end_pos];
                    if (x == t) {
                        is_prefix = true;
                        break;
                    }
                }
                bool is_suffix = false;
                string t_rev{t.rbegin(), t.rend()};
                string y = "";
                for (int start_pos = n - 1; start_pos >= 0; --start_pos) {
                    y += s[start_pos];
                    if (y == t_rev) {
                        is_suffix = true;
                        break;
                    }
                }
                if (is_prefix && is_suffix) {
                    continue;
                }
                if (is_prefix || is_suffix) {
                    ++cnt;
                }
            }
        }
        cout << cnt << '\n';
    }
    
    return 0;
}

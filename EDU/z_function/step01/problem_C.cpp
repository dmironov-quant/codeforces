// https://codeforces.com/edu/course/2/lesson/3/1/practice/contest/272260/problem/C

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int n = static_cast<int>(s.size());
        
        string t;
        cin >> t;
        int k = static_cast<int>(t.size());

        int cnt = 0;
        vector<int> idxs;
        for (int i = 0; i < n; ++i) {
            int coincides = 0;
            for (int j = 0; j < k; ++j) {
                if (i+j >= n) {
                    break;
                }
                if (t[j] == '?') {
                    ++coincides;
                    continue;
                }
                if (s[i+j] != t[j]) {
                    break;
                }
                ++coincides;
            }
            if (coincides == k) {
                idxs.push_back(i);
                ++cnt;
            }
        }

        cout << cnt << '\n';
        for (const int& idx : idxs) {
            cout << idx << " ";
        }
        cout << '\n';
    }
    
    return 0;
}

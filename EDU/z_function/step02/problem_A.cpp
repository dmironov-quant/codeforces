// https://codeforces.com/edu/course/2/lesson/3/2/practice/contest/272261/problem/A


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = static_cast<int>(s.size());
    vector<int> zn(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j+i < n && s[j+i] == s[j]) {
                ++zn[i];
            }
            else {
                break;
            }
        }
    }
    zn[0] = 0;

    for (const auto& z : zn) {
        cout << z << ' ';
    }
    
    return 0;
}

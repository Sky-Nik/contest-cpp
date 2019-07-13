#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define fore(i, l, r) for(int i = l; i < r; ++i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 4 != 0) {
        cout << "===";
    } else {
        string s;
        cin >> s;
        int a = 0, c = 0, g = 0, t = 0;
        forn(i, n) {
            if (s[i] == 'A') {
                ++a;
            } elif (s[i] == 'C') {
                ++c;
            } elif (s[i] == 'G') {
                ++g;
            } elif (s[i] == 'T') {
                ++t;
            }
        }
        //cout << "a = " << a << ", c = " << c << ", g = " << g << ", t = " << t << "\n";
        int k = n >> 2;
        if (a > k || c > k || g > k || t > k) {
            cout << "===";
        } else {
            forn(i, n) {
                if (s[i] == '?') {
                    if (a < k) {
                        s[i] = 'A';
                        ++a;
                    } elif (c < k) {
                        s[i] = 'C';
                        ++c;
                    } elif (g < k) {
                        s[i] = 'G';
                        ++g;
                    } else {
                        s[i] = 'T';
                        ++t;
                    }
                }
            }
            cout << s;
        }
    }
    return 0;
}
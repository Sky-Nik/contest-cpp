#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

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

bool face(char c1, char c2, char c3, char c4) {
  vector<char> vc1{c1, c2, c3, c4};
  sort(begin(vc1), end(vc1));
  vector<char> vc2{'f', 'a', 'c', 'e'};
  sort(begin(vc2), end(vc2));
	return vc1[0] == vc2[0] && vc1[1] == vc2[1] && vc1[2] == vc2[2] && vc1[3] == vc2[3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> i(n);
    cin >> i;
    int k = 0;
    fore(r, 1, n) fore(c, 1, m) if (face(i[r - 1][c - 1], i[r - 1][c], i[r][c - 1], i[r][c])) ++k;
    cout << k;
    return 0;
}
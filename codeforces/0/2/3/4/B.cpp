#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ifstream fin;
    fin.open("input.txt");
    int n, k, ai;
    fin >> n >> k;
    vector<pii> a(n);
    forn(i, n) {
    	fin >> ai;
    	a[i] = make_pair(ai, i + 1);
    }
    fin.close();
    sort(begin(a), end(a));
    ofstream fout;
    fout.open("output.txt");
    fout << a[n - k].first << "\n";
    forn(i, k) fout << a[n - 1 - i].second << " ";
    fout.close();
    return 0;
}
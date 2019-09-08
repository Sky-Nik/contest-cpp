#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < static_cast<int>(_n); ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        is >> e;
    }
    return is;
}

template<typename T>
inline ostream& operator << (ostream& os, const vector<T>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
     os << "\n";
    return os;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, answer_1 = 0, answer_2;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a;
    answer_2 = *max_element(begin(a), end(a)) + m;
    priority_queue<int> q;
    forn(i, n) q.push(-a[i]);
    forn(i, m) {
    	int c = q.top();
    	q.pop();
    	q.push(c - 1);
    }
    forn(i, n) {
        answer_1 = max(answer_1, -q.top());
        q.pop();
    }
    cout << answer_1 << " " << answer_2;
    return 0;
}

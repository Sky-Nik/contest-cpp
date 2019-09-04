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
#define sum(a) accumulate(begin(a), end(a), 0ll)}

int n, l;
const int MAXN = 1000 + 10;
int x[MAXN];
int b[MAXN];
ld dp[MAXN];

ld binary_search_r(ld lower_bound, ld upper_bound, bool(*checker) (ld), ld precision) {
    ld middle;
    while (lower_bound + precision < upper_bound) {
        middle = (lower_bound + upper_bound) / 2.;
        if ((*checker)(middle)) {
            upper_bound = middle;
        } else {
            lower_bound = middle;
        }
    }
    return lower_bound;
}

inline ostream& operator << (ostream& os, const vector<int>& v) {
    for (const auto& e: v) {
        os << e << " ";
    }
    os << "\n";
    return os;
}

bool checker(ld R) {
    dp[0] = 0.;
    fore(i, 1, n) {
        dp[i] = numeric_limits<ld>::infinity();
        forn(j, i) {
            dp[i] = min(dp[i], dp[j] + sqrt(abs(x[i] - x[j] - l)) - R * b[i]);
        }
    }
    return dp[n - 1] <= 0;
}

vector<int> answer_finder(ld K) {
    vector<int> prec(n, 0);
    dp[0] = 0.;
    fore(i, 1, n) {
        dp[i] = numeric_limits<ld>::infinity();
        forn(j, i) {
            if (dp[i] > dp[j] + sqrt(abs(x[i] - x[j] - l)) - K * b[i]) {
                dp[i] = dp[j] + sqrt(abs(x[i] - x[j] - l)) - K * b[i];
                prec[i] = j;
            }
        }
    }
    int current = n - 1;
    vector<int> answer = { current };
    while (prec[current] != 0) {
        current = prec[current];
        answer.push_back(current);
    }
    reverse(begin(answer), end(answer));
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    ++n;
    x[0] = 0;
    b[0] = 0;
    fore(i, 1, n + 1) cin >> x[i] >> b[i];
    cout << answer_finder(binary_search_r(0., 10000., checker, 1e-7));
    return 0;
}

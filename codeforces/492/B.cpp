#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, l;
const int MAXN = 1000 + 100;
ll a[MAXN];

/* Binary search to find 
 * the smallest value of x 
 * with checker(x) true.
 * Typename T should model
 * totally ordered set. */
template <typename T>
T binary_search(T lower_bound, T upper_bound, bool(*checker) (T)) {
    T middle;
    while (lower_bound < upper_bound) {
        middle = (lower_bound + upper_bound) >> 1;
        if ((*checker)(middle)) {
            upper_bound = middle;
        } else {
            lower_bound = middle + 1;
        }
    }
    return lower_bound;
}

bool checker(ll d) {
    bool answer = true;
    if (a[0] - d > 0) {
        answer = false;
    }
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] + d < a[i] - d) {
            answer = false;
        }
    }
    if (a[n - 1] + d < l) {
        answer = false;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l;
    l <<= 1;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] <<= 1;
    }
    sort(a, a + n);
    cout << fixed << setprecision(9) << (binary_search(0ll, l, checker) / 2.);
    return 0;
}

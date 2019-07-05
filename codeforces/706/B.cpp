#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q, m;
const int MAXN = 100000 + 100;
int x[MAXN];

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

bool checker(int num_stores) {
    return x[num_stores] > m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    x[n] = 0;
    x[n + 1] = numeric_limits<int>::max();
    sort(x, x + n + 1);
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> m;
        cout << binary_search(0, n + 1, checker) - 1 << "\n";
    }
    return 0;
}

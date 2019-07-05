#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll b;
const int MAXN = 200000 + 100;
ll a[MAXN], p[MAXN];

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

bool checker(int dorm_number) {
    return p[dorm_number] >= b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    p[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        p[i + 1] = a[i] + p[i];
    }
    int lower_bound = 0, upper_bound = n;
    for (int i = 0; i < m; ++i) {
        cin >> b;
        int dorm_number = binary_search(lower_bound, upper_bound, checker);
        cout << dorm_number << " " << b - p[dorm_number - 1] << "\n";
        lower_bound = dorm_number;
    }
    return 0;
}

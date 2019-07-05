#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

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

bool checker(int num_ruler_segments) {
    int x = num_ruler_segments >> 1;
    int y = num_ruler_segments - x;
    return (n <= (ll)x * y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << binary_search(0, (n << 1), checker);
    return 0;
}

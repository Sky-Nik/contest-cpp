#include <bits/stdc++.h>

using namespace std;

int n, k;

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


bool checker(int number_of_problems) {
    // cout << "checker(" << number_of_problems << ") called, ";
    int total_time = k + ((5 * number_of_problems * (number_of_problems + 1)) >> 1);
    bool answer = (number_of_problems > n) || (total_time > 240);
    // cout << "will return " << answer << "\n";
    return answer;
}


int main() {
    cin >> n >> k;
    cout << binary_search(0, 20, checker) - 1;
    return 0;
}

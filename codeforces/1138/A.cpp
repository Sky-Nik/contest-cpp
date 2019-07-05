#include <bits/stdc++.h>

using namespace std;

int n;
enum sushi_type { TUNA = 1, EEL = 2 };

const int MAXN = 100000 + 100;
int sushi_types[MAXN];

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

bool checker(int half_segment_length) {
    // cout << "checker(" << half_segment_length << ") called,";
    int starting_position = 0;
    int max_position = n - (half_segment_length << 1);
    bool possible_to_choose = false;
    while (!possible_to_choose && (starting_position <= max_position)) {
        bool to_continue = false;
        for (int i = 1; !to_continue && (i < half_segment_length); ++i) {
            if (sushi_types[starting_position] != sushi_types[starting_position + i]) {
                starting_position = starting_position + i;
                to_continue = true;
            }
        }
        while (!to_continue && (sushi_types[starting_position] == sushi_types[starting_position + half_segment_length]) && (starting_position <= max_position)) {
            ++starting_position;
        }
        for (int i = 1; !to_continue && (i < half_segment_length); ++i) {
            if (sushi_types[starting_position + i] == sushi_types[starting_position + half_segment_length + i]) {
                starting_position = starting_position + half_segment_length + i;
                to_continue = true;
            }
        }
        if (!to_continue && (starting_position <= max_position)) {
            possible_to_choose = true;
        }
    }
    // cout << "will return " << !possible_to_choose << "\n";
    return !possible_to_choose;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> sushi_types[i];
    }
    cout << ((binary_search(0, n + 10, checker) - 1) << 1);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    char max_letter = 'a' - 1;
    int num_occurences = 0;
    for (char c: s) {
        if (c == max_letter) {
            ++num_occurences;
        } else if (c > max_letter) {
            max_letter = c;
            num_occurences = 1;
        }
    }
    cout << string(num_occurences, max_letter);
    return 0;
}

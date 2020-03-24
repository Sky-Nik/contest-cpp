/* INPUT
3 3 2
1 2
2 1
3 3
3 2
->
3
DRD

5 4 3
3 4
3 1
3 3
5 3
1 3
1 4
->
9
DDLUUUURR
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, k;

char next(pair<int, int>& rc) {
    if (rc.second & 1) {
        if (!rc.first) {
            ++rc.second;
            return 'R';
        } else {
            --rc.first;
            return 'U';
        }
    } else {
        if (rc.first + 1 == n) {
            ++rc.second;
            return 'R';
        } else {
            ++rc.first;
            return 'D';
        }
    }
}

char prev(pair<int, int>& rc) {
    if (rc.second & 1) {
        if (rc.first + 1 == n) {
            --rc.second;
            return 'L';
        } else {
            ++rc.first;
            return 'D';
        }
    } else {
        if (!rc.first) {
            --rc.second;
            return 'L';
        } else {
            --rc.first;
            return 'U';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;

    vector<pair<int, int>> s(k), f(k);
    for (auto& [x, y] : s) {
        cin >> x >> y;
    }
    for (auto& [x, y] : f) {
        cin >> x >> y;
    }

    cout << 2 * (n * m - 1) << "\n";
    pair<int, int> start = make_pair(0, 0),
                   finish = m & 1 ? make_pair(n - 1, m - 1) : make_pair(0, m - 1);
    auto current = start;
    while (current != finish) {
        cout << next(current);
    }
    while (current != start) {
        cout << prev(current);
    }

    return 0;
}

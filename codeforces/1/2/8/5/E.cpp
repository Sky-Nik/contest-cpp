#include <bits/stdc++.h>
using namespace std;

enum endpoint_t {
    kLeft = 0,
    kRight = 1,
};

struct Endpoint {
    int coordinate;
    endpoint_t type;
    int segment_id;
};

inline bool cmpl(const Endpoint& lhs, const Endpoint& rhs) {
    return make_pair(lhs.coordinate, lhs.type) < make_pair(rhs.coordinate, rhs.type);
}

inline bool cmpr(const Endpoint& lhs, const Endpoint& rhs) {
    return make_pair(rhs.coordinate, rhs.type) < make_pair(lhs.coordinate, lhs.type);
}

int solve(vector<Endpoint>& endpoints, int n) {
    vector<int> cnt(n, 0);
    int nc = 0;

    set<int> active_segments;
    sort(endpoints.begin(), endpoints.end(), cmpl);
    for (int i = 0; i < (n << 1);) {
        int coordinate = endpoints[i].coordinate;

        int j = i;
        while (j < (n << 1) && coordinate == endpoints[j].coordinate)
            ++j;

        int lc = 0;
        for (int k = i; k < j; ++k) {
            if (endpoints[k].type == kLeft) {
                active_segments.insert(endpoints[k].segment_id);
                ++lc;
            }
        }

        if (active_segments.size() == lc && lc == 1)
            for (auto active_segment: active_segments)
                --cnt[active_segment];

        set<int> to_erase;

        int rc = 0;
        for (int k = i; k < j; ++k) {
            if (endpoints[k].type == kRight) {
                to_erase.insert(endpoints[k].segment_id);
                ++rc;
            }
        }

        if (active_segments.size() == rc && rc == 1)
            for (auto active_segment: active_segments)
                --cnt[active_segment];

        for (auto to_erase_i: to_erase)
            active_segments.erase(to_erase_i);

        if (active_segments.empty())
            ++nc;

        if (active_segments.size() == 1)
            for (auto active_segment: active_segments)
                ++cnt[active_segment];

        i = j;
    }

    for (int i = 0; i < n; ++i)
        if (cnt[i] == -2)
            cnt[i] = -1;

    // cout << "cnt:";
    // for (auto cnti: cnt)
    //     cout << " " << cnti;
    // cout << "\n";

    return nc + *max_element(cnt.begin(), cnt.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t --> 0) {
        int n;
        cin >> n;

        vector<Endpoint> endpoints(n << 1);
        for (int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            endpoints[i << 1] = { l, kLeft, i };
            endpoints[(i << 1) | 1] = { r, kRight, i };
        }

        cout << solve(endpoints, n) << "\n";
    }

    return 0;
}

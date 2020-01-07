#include <bits/stdc++.h>
using namespace std;

struct mi {
    int m1i = -1, m2i = -1, m3i = -1;

    int sz() const {
        if (m3i != -1) {
            return 3;
        } else if (m2i != -1) {
            return 2;
        } else if (m1i != -1) {
            return 1;
        } else {
            return 0;
        }
    }

    void print() const {
        cout << sz();

        if (sz() >= 1) {
            cout << " popStack";

            if (sz() >= 2) {
                cout << " popQueue";

                if (sz() >= 3) {
                    cout << " popFront";
                }
            }
        }

        cout << "\n";
    }
};

struct p {
    int n, i;

    bool operator<(const p& o) const {
        return make_pair(n, i) < make_pair(o.n, o.i);
    }
};

mi h(const set<p>& sp) {
    int m3 = 0, m2 = 0, m1 = 0;
    mi ans{-1, -1, -1};

    for (const auto& pi: sp) {
        if (pi.n > m1) {
            ans.m3i = ans.m2i;
            m3 = m2; 
            ans.m2i = ans.m1i;
            m2 = m1; 
            ans.m1i = pi.i;
            m1 = pi.n;
        } else if (pi.n > m2) {
            ans.m3i = ans.m2i;
            m3 = m2;
            ans.m2i = pi.i;
            m2 = pi.n;
        } else if (pi.n > m3) {
            ans.m3i = pi.i;
            m3 = pi.n;
        }
    }

    return ans;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& ai: a) cin >> ai;

    vector<mi> miv;
    set<p> sp;
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i]) {
            sp.insert({a[i], i});
        } else {
            miv.push_back(h(sp));
            sp.clear();
        }
    }

    vector<int> actions(n, 4);
    for (auto mi: miv) {
        if (mi.m3i != -1) actions[mi.m3i] = 3;
        if (mi.m2i != -1) actions[mi.m2i] = 2;
        if (mi.m1i != -1) actions[mi.m1i] = 1;
    }

    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i]) {
            if (actions[i] == 1) cout << "pushStack\n";
            if (actions[i] == 2) cout << "pushQueue\n";
            if (actions[i] == 3) cout << "pushFront\n";
            if (actions[i] == 4) cout << "pushBack\n";
        } else {
            miv[j].print();
            ++j;
        }
    }

    return 0;
}

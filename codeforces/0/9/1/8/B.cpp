#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define elif else if
#define forn(i, n) for(int i = 0; i < n; ++i)
#define sort(v) sort(begin(v), end(v))

template<typename T>
inline istream& operator >> (istream& is, vector<T>& v) {
    for (auto& e: v) {
        cin >> e;
    }
    return is;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    map<string, string> mp;
    forn(i, n) {
        string name, ip;
        cin >> name >> ip;
        mp[ip] = name;
    }
    forn(i, m) {
        string cmd, ip;
        cin >> cmd >> ip;
        cout << cmd << " " << ip << " #" << mp[ip.substr(0, ip.length() - 1)] << "\n";
    }
    return 0;
}
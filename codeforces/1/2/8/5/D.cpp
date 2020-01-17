#include <bits/stdc++.h>
using namespace std;

string bitstr(int64_t ai, int nbit) {
    string r;

    for (int i = 0; i < nbit; ++i) {
        if (ai & 1)
            r += '1';
        else
            r += '0';

        ai >>= 1;
    }

    reverse(r.begin(), r.end());

    return r;
}

int64_t ibitstr(string& s) {
    reverse(s.begin(), s.end());

    int64_t p = 1, r = 0;
    for (char c: s) {
        if (c == '1')
            r += p;

        p <<= 1;
    }

    return r;
}

string solve(vector<string>& b, int bpos = 0) {
    if (bpos >= b[0].length())
        return "";

    vector<string> b0, b1;

    for (auto bi: b) {
        if (bi[bpos] == '0')
            b0.push_back(bi);
        else
            b1.push_back(bi);
    }

    if (b0.empty())
        return '0' + solve(b1, bpos + 1);

    if (b1.empty())
        return '0' + solve(b0, bpos + 1);

    string s0 = solve(b0, bpos + 1), s1 = solve(b1, bpos + 1);

    if (s0 < s1)
        return '1' + s0;
    else
        return '1' + s1; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (auto& ai: a)
        cin >> ai;

    vector<string> b(n);
    for (int i = 0; i < n; ++i)
        b[i] = bitstr(a[i], 30);

    string s = solve(b);

    // cout << "s = " << s << "\n";
    
    cout << ibitstr(s);

    return 0;
}
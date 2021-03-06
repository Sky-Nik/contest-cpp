#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;

#define elif else if
#define forn(_i, _n) for(int _i = 0; _i < _n; ++_i)
#define fore(_i, _l, _r) for(int _i = _l; _i < _r; ++_i)
#define sum(a) accumulate(begin(a), end(a), 0ll)

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
    int n;
    cin >> n;
    map<int, string> m = {
    	{0, "zero"},
    	{1, "one"},
    	{2, "two"},
    	{3, "three"},
    	{4, "four"},
    	{5, "five"},
    	{6, "six"},
    	{7, "seven"},
    	{8, "eight"},
    	{9, "nine"},
    	{10, "ten"},
    	{11, "eleven"},
    	{12, "twelve"},
    	{13, "thirteen"},
    	{14, "fourteen"},
    	{15, "fifteen"},
    	{16, "sixteen"},
    	{17, "seventeen"},
    	{18, "eighteen"},
    	{19, "nineteen"},
    	{20, "twenty"},
    	{30, "thirty"},
    	{40, "forty"},
    	{50, "fifty"},
    	{60, "sixty"},
    	{70, "seventy"},
    	{80, "eighty"},
    	{90, "ninety"},
    };
    if (n <= 20 || n % 10 == 0) {
    	cout << m[n];
    } else {
    	cout << m[10 * (n / 10)] + '-' + m[n % 10];
    }
    return 0;
}
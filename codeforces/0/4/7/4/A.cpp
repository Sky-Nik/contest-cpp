#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define forn(i, n) for(int i = 0; i < n; ++i)

int main() {
	vector<string> keyboard{"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
    char shift;
    string message;
    cin >> shift >> message;
    for (char ch: message) {
    	forn(r, 3) {
    		forn(c, 10) {
    			if (keyboard[r][c] == ch) {
    				if (shift == 'L') {
    					cout << keyboard[r][c + 1];
    				} else { // if (shift == 'R')
    					cout << keyboard[r][c - 1];
    				}
    				goto label;
    			}
    		}
    	}
    	label:;
    }
    return 0;
}
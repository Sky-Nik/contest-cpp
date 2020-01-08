#include <bits/stdc++.h>
using namespace std;

const int64_t kMaxA = 100'000, kMaxB = 60;

enum Player {
    kMissing = 0,
    kStas = 1,
    kMasha = 2,
    kUndefined = 3
};

Player pnot(const Player& player) {
    if (player == kMasha)
        return kStas;
    if (player == kStas)
        return kMasha;
    return kUndefined;
}

void PrintPlayer(const Player& player) {
    if (player == kMissing) {
        cout << "Missing";
    } else if (player == kStas) {
        cout << "Stas";
    } else {
        cout << "Masha";
    }    
}

// O(b) is ok because b is small enough (like < 60 or so)
int64_t mpow(int64_t a, int64_t b) {
    int64_t r = 1;

    for (int i = 0; i < b; ++i)
        r *= a;

    return r;
}

Player dfs(int64_t a, int64_t b, int64_t n, const Player& to_move, vector<vector<Player>>& dp) {
    if (dp[a][b] != kUndefined)
        return dp[a][b];

    // First special case a is 1:
    if (a == 1) {
        if (mpow(2, b) >= n)
            return dp[a][b] = kMissing;
        else if (dfs(a + 1, b, n, pnot(to_move), dp) == pnot(to_move))
            return dp[a][b] = pnot(to_move);
        else
            return dp[a][b] = dfs(a, b + 1, n, pnot(to_move), dp);
    }

    // Second special case b is 1:
    if (b == 1) {
        if (mpow(a, b + 1) >= n) {
            if ((n - a) & 1)
                return dp[a][b] = to_move;
            else
                return dp[a][b] = pnot(to_move);
        }
    }

    // It is possible to move in b direction
    if (mpow(a, b + 1) < n)
        if (dfs(a, b + 1, n, pnot(to_move), dp) == pnot(to_move))
            return dp[a][b] = pnot(to_move);

    // It is possible to move in a direction
    if (mpow(a + 1, b) < n)
        if (dfs(a + 1, b, n, pnot(to_move), dp) == pnot(to_move))
            return dp[a][b] = pnot(to_move);

    // We cannot move anywhere
    return dp[a][b] = to_move;
}

Player DetermineWinner(int64_t a, int64_t b, int64_t n, const Player& to_move) {
    vector<vector<Player>> dp(kMaxA, vector<Player>(kMaxB, kUndefined));
    return dfs(a, b, n, to_move, dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t a, b, n;
    cin >> a >> b >> n;

    auto player = DetermineWinner(a, b, n, kStas);

    PrintPlayer(player);

    return 0;
}

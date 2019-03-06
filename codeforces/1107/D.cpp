#include <bits/stdc++.h>

using namespace std;

void solve(int n, vector<vector<int>>& board) {
	int x = n;

	for (int i = 0; i < n; ++i)
		board[i].push_back(1 - board[i][n - 1]);

	vector<int> board_row_n(n);
	for (int i = 0; i < n; ++i)
		board_row_n.push_back(1 - board[n - 1][i]);
	board.push_back(board_row_n);

	for (int i = 0; i < n; ++i) {
		int cur = board[i][0], count = 1;

		for (int j = 1; j <= n; ++j) {
			if (board[i][j] != cur) {
				x = __gcd(x, count);
				cur = board[i][j];
				count = 0;
			}

			++count;
		}
	}

	for (int j = 0; j < n; ++j) {
		int cur = board[0][j], count = 1;
		
		for (int i = 1; i <= n; ++i) {
			if (board[i][j] != cur) {
				x = __gcd(x, count);
				cur = board[i][j];
				count = 0;
			}

			++count;
		}
	}

	cout << x << "\n";
}

int main() {
	int n; cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		string row; cin >> row;
		for (int j = 0; (j << 2) < n; ++j) {
      char from = '0';
      if (row[j] > '9')
        from = 'A' - 10;

			board[i][(j << 2) + 0] = ((row[j] - from) & 8) != 0;
			board[i][(j << 2) + 1] = ((row[j] - from) & 4) != 0;
			board[i][(j << 2) + 2] = ((row[j] - from) & 2) != 0;
			board[i][(j << 2) + 3] = ((row[j] - from) & 1) != 0;
		}
	}

	solve(n, board);

	return 0;
}
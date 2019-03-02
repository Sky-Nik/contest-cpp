#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> get_adjacent(pair<int, int> ij, int n, int m) {
	int i = ij.first, j = ij.second;

	vector<pair<int, int>> ans;

	if (i > 0)
		ans.push_back(make_pair(i - 1, j));

	if (i + 1 < n)
		ans.push_back(make_pair(i + 1, j));

	if (j > 0)
		ans.push_back(make_pair(i, j - 1));

	if (j + 1 < m)
		ans.push_back(make_pair(i, j + 1));

	return ans;
}

void process_player(int n, int m, int pi, int si, vector<string>& board, 
	queue<pair<int, int>>& qsi) {
	queue<pair<pair<int, int>, int>> qs;
	while (!qsi.empty()) {
		auto ij = qsi.front();
		qsi.pop();
		qs.push(make_pair(ij, 0));
	}

	while (!qs.empty() && qs.front().second < si) {
		pair<int, int> ij = qs.front().first;

		for (auto ij_adj: get_adjacent(ij, n, m)) {
			int i = ij_adj.first, j = ij_adj.second;
			if (board[i][j] == '.') {
				board[i][j] = '1' + pi;
				qs.push(make_pair(ij_adj, qs.front().second + 1));
			}
		}

		qs.pop();
	}

	while(!qs.empty()) {
		auto ijs = qs.front();
		qs.pop();
		qsi.push(ijs.first);
	}
}

void solve(int n, int m, int p, vector<int>& s, vector<string>& board) {
	vector<queue<pair<int, int>>> qs(p);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] != '.' && board[i][j] != '#')
				qs[board[i][j] - '1'].push(make_pair(i, j));

	while (true) {
		bool cont = false;
		for (const auto & qsi: qs)
			if (!qsi.empty())
				cont = true;

		if (!cont)
			break;

		for (int i = 0; i < p; ++i)
			if (!qs[i].empty())
				process_player(n, m, i, s[i], board, qs[i]);
	}

	vector<int> count(p, 0);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (board[i][j] != '.' && board[i][j] != '#')
				++count[board[i][j] - '1'];

	for (int pi: count)
		cout << pi << " ";
	cout << "\n";
}

int main() {
	int n, m, p; cin >> n >> m >> p;
	
	vector<int> s(p);
	for (int i = 0; i < p; ++i)
		cin >> s[i];

	vector<string> board(n);
	for (int i = 0; i < n; ++i)
		cin >> board[i];

	solve(n, m, p, s, board);

	return 0;
}
#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<int> vint;


void solve(size_t n, uint k, vint& a) {
	size_t l = 0, r = 0;
	int cur = 1;
	size_t answer_l = 0, answer_r = 0;

	vint cnt(1000010, 0);
	cnt[a[0]] = 1;

	while (r + 1 < n) {
    // std::cout << "l =  " << l << ", r = " << r << ", cur = " << cur << "\n\n";

		++r;
		++cnt[a[r]];

		if (cnt[a[r]] == 1)
			++cur;

		if (cur > k) {
			if (r - l - 1 > answer_r - answer_l) {
				answer_l = l;
				answer_r = r - 1;
			}
		}

		while (cur > k) {
			--cnt[a[l]];
			
      if (cnt[a[l]] == 0)
				--cur;
        
      ++l;
		}
	}

	if (r - l > answer_r - answer_l) {
		answer_l = l;
		answer_r = r;
	}

	std::cout << answer_l + 1 << " " << answer_r + 1;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	size_t n; uint k;
	std::cin >> n >> k;

	vint a(n);
	for (size_t i = 0; i < n; ++i)
		std::cin >> a[i];

	solve(n, k, a);

	return 0;
}
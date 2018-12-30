#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>

constexpr auto M_PI = 3.14159265358979323846;

typedef long double ldouble;
typedef long long llong;

void solve(llong x1, llong y1, llong r1, llong x2, llong y2, llong r2) {
	ldouble answer;

	llong d_squared = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if (d_squared >= (r1 + r2) * (r1 + r2)) answer = 0;
	else if (d_squared <= (r2 - r1) * (r2 - r1)) 
		answer = M_PI * std::min(r1, r2) * std::min(r1, r2);
	else {
		ldouble alpha = acosl((r2 * r2 + d_squared - r1 * r1) / (2 * r2 * sqrtl(d_squared)));
		ldouble s = alpha * r2 * r2;
		ldouble t = r2 * r2 * sinl(alpha) * cosl(alpha);
		answer += s - t;

		alpha = acosl((r1 * r1 + d_squared - r2 * r2) / (2 * r1 * sqrtl(d_squared)));
		s = alpha * r1 * r1;
		t = r1 * r1 * sinl(alpha) * cosl(alpha);
		answer += s - t;
	}

	std::cout << std::setprecision(std::numeric_limits<ldouble>::digits10 + 1) << answer;
}

int main() {
	llong x1, y1, r1, x2, y2, r2;
	std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

	solve(x1, y1, r1, x2, y2, r2);

	return 0;
}
#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <limits>

const int kColors = 20;

struct BallSequence {
    int length;
    std::vector<int> colors;
};

auto ReadBallSequence(std::istream& in = std::cin) {
    BallSequence balls;
    in >> balls.length;
    balls.colors.resize(balls.length);
    for (auto& ball : balls.colors) {
        in >> ball;
    }
    return balls;
}

auto CountTwoColorSwaps(const BallSequence& balls, int left_color, int right_color) {
    int64_t num_swaps = 0;

    int num_left_color_balls = 0, num_right_color_balls = 0;

    for (const auto& color : balls.colors) {
        if (color == left_color) {
            ++num_left_color_balls;
            num_swaps += num_right_color_balls;
        } else if (color == right_color) {
            ++num_right_color_balls;
        }
    }

    return num_swaps;
}

int64_t CalculateDp(std::vector<int64_t>* dp, const std::vector<std::vector<int64_t>>& cnt,
    int mask) {
    if ((*dp)[mask] == std::numeric_limits<int64_t>::max()) {
        for (int left_color = 0; left_color < kColors; ++left_color) {
            if ((mask >> left_color) & 1) {
                int64_t current = CalculateDp(dp, cnt, mask - (1 << left_color));

                for (int lefter_color = 0; lefter_color < kColors; ++lefter_color) {
                    if (lefter_color != left_color && (mask >> lefter_color) & 1) {
                        current += cnt[lefter_color][left_color];
                    }
                }

                (*dp)[mask] = std::min((*dp)[mask], current);
            }
        }
    }

    return (*dp)[mask];
}

auto CalculateMinSwaps(const BallSequence& balls) {
    std::vector<std::vector<int64_t>> cnt(kColors, std::vector<int64_t>(kColors, 0));

    for (int left_color = 0; left_color < kColors; ++left_color) {
        for (int right_color = 0; right_color < kColors; ++right_color) {
            if (left_color != right_color) {
                cnt[left_color][right_color] =
                    CountTwoColorSwaps(balls, left_color + 1, right_color + 1);
            }
        }
    }

    std::vector<int64_t> dp(1 << kColors, std::numeric_limits<int64_t>::max());
    dp[0] = 0;

    return CalculateDp(&dp, cnt, (1 << kColors) - 1);
}

void PrintMinSwaps(int64_t min_swaps, std::ostream& out = std::cout) {
    out << min_swaps << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    auto balls = ReadBallSequence();
    auto min_swaps = CalculateMinSwaps(balls);
    PrintMinSwaps(min_swaps);

    return 0;
}

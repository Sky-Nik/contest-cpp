#include <iostream>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int t, ac, p;
    std::string o, a;
    std::cin >> t;
    while (t--) {
        std::cin >> ac >> o;
        int s = 0;
        while (ac--) {
            std::cin >> a;
            if (a == "CONTEST_WON") {
                std::cin >> p;
                if (p < 20) {
                    s += 300 + 20 - p;
                } else {
                    s += 300;
                }
            } else if (a == "TOP_CONTRIBUTOR") {
                s += 300;
            } else if (a == "BUG_FOUND") {
                std::cin >> p;
                s += p;
            } else {  // CONTEST_HOSTED
                s += 50;
            }
        }
        if (o == "INDIAN") {
            std::cout << s / 200 << "\n";
        } else {  // NON_INDIAN
            std::cout << s / 400 << "\n";
        }
    }

    return 0;
}

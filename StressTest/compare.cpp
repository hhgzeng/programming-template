#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    system("g++ -std=gnu++23 stress__Generator.cpp -o stress__Generator");
    system("g++ -std=gnu++23 stress__Good.cpp -o stress__Good");
    system("g++ -std=gnu++23 stress.cpp -o stress");
    for (int t = 1; ; t++) {
        system("./stress__Generator");
        system("./stress__Good");
        system("./stress");
        std::cout << "test #" << t << "\n";
        if (system("diff good.txt bad.txt")) {
            std::cout << "Wrong Answer!\n";
            exit(0);
        } else {
            std::cout << "Accepted!\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

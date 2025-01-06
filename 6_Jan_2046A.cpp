#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<int> b(n);

    for(int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int other = INT_MIN, total = 0;

    for(int i = 0; i < n; i++) {
        total += std::max(a[i], b[i]);
        other = std::max(other, std::min(a[i], b[i]));
    }

    std::cout << total + other << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
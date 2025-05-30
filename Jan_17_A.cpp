#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
//using u128 = unsigned __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> y[i];
    }
    
    int ans = 4 * m;
    for (int i = 1; i < n; i++) {
        ans += 2 * (x[i] + y[i]);
    }
    std::cout << ans << "\n";
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
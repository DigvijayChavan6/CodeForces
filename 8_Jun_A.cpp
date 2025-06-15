#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int x = 0;
    std::cin >> x;
    
    int a = 0, b = 0, c = 0;
    int ans = 0;
    while (a < x || b < x || c < x) {
        std::vector<int> v = {a, b, c};
        std::sort(v.begin(), v.end());

        // Try to increase the smallest value, respecting the constraint
        int can_go = std::min(x - v[0], v[1] / 2);
        if (can_go == 0) can_go = 1;

        v[0] += can_go;
        a = v[0], b = v[1], c = v[2];
        ans++;
    }
    std::cout << ans+2 << std::endl;
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
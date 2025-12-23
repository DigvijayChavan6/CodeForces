#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    i64 n = 0;
    std::cin >> n;
    std::vector<int> vals(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vals[i];
    }

    i64 sum = 0;
    
    for (int i = 1; i < n; i++) {
        sum += std::abs(vals[i] - vals[i - 1]);
    }
    
    i64 ans = sum;

    for(int i = 0; i < n; i++) {
        i64 cur = sum;
        if (i == 0) {
            cur -= std::abs(vals[i+1] - vals[i]);
        }else if(i == n - 1) {
            cur -= std::abs(vals[i] - vals[i-1]);
        } else {
           cur -= std::abs(vals[i] - vals[i-1]) + std::abs(vals[i] - vals[i+1]);
           cur += std::abs(vals[i+1] - vals[i-1]);
        }
        ans = std::min(ans, cur);
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
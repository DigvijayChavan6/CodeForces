#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    
    for (int i = 1; i < n; ++i) {
        if ((s[i-1] == ')' ) && (s[i] == '(' )) {
            std::cout << "YES" << std::endl;
            return;
        }
    }
    std::cout << "NO" << std::endl;
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
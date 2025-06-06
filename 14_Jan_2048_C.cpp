#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    std::string s;
    std::cin >> s;
    
    std::string ans;
    int n = s.size();
    int L = -1, R = -1;
    for (int r = 0; r < n; r++) {
        auto t = s;
        int i = r;
        for (int l = r; l >= 0; l--) {
            if (s[l] == '1') {
                t[n - 1 - (r - l)] ^= 1;
                if (t[n - 1 - (r - l)] == '1') {
                    i = l;
                }
            }
        }
        t = s;
        for (int l = r; l >= i; l--) {
            if (s[l] == '1') {
                t[n - 1 - (r - l)] ^= 1;
            }
        }
        if (t > ans) {
            ans = t;
            L = i;
            R = r;
        }
    }
    
    std::cout << 1 << " " << n << " " << L + 1 << " " << R + 1 << "\n";
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
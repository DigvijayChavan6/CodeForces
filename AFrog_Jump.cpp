#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0, a = 0, b = 0;
    std::cin >> n >> a >> b;
    if(abs(a-b)%2 == 1){
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
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
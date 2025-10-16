#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;

    for(int i = 0; i < 2*n; i++) {
        int x;
        if(i < n-1){
            x = n - 1 - i;
        }else if(i == n-1){
            x = n;
        }else if (i < 2*n -1){
            x = i - n + 1;
        }else{
            x = n;
        }

        std::cout << x << " ";
    }
    std::cout << "\n";
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
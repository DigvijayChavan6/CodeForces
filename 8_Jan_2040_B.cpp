#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

int solve() {
    int n = 0;
    std::cin >> n;

    int a = 1;

    int p = 1;

    while(p < n){
        p = 2*(p+1);
        a++;
    }

    return a; 
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        std::cout<< solve() << "\n";
    }
    
    return 0;
}
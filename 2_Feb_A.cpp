#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

bool solve() {
    int n = 0, t = 0;
    std::cin >> n;

    std::set<int> a;
    std::set<int> b;

    for(int i = 0; i < n; ++i){
        std::cin >> t;
        a.insert(t);
    }

    for(int i = 0; i < n; ++i){
        std::cin >> t;
        b.insert(t);
    }

    return a.size() + b.size() >= 4;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        if(solve()){
            std::cout << "YES" << std::endl;
        }else{
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}
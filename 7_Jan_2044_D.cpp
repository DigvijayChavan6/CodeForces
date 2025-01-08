#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::map<int, int> mp;
    std::vector<int> v;
    v[0] = a[0];
    mp[v[0]]++;
    
    int mx = 1;

    if(n >= 2){
        v[1] = a[1];
        mp[v[1]]++;
        mx = std::max(mx, mp[v[1]]);
    }

    for (int i = 2; i < n; i++) {
        
    }

    for (int i = 0; i < n; i++) {
        std::cout << v[i] << " ";
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
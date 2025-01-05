#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> v(n, 0);

    int c = 1;

    for(int i = k-1; i < n; i+=k) {
        v[i] = c++;
    }

    for(int i = 0; i < n; i++) {
        if(v[i] == 0){
            v[i] = c++;
        }
    }

    for(int val : v){
        std::cout << val << " ";
    }

    std::cout << std::endl;

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
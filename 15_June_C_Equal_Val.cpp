#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int64_t cost = int64_t(1e18);
    
    int i = 0, j = 0;

    while(i < n){
        j = i;
        while(j+1 < n && a[j + 1] == a[j]) {
            j++;
        }
        int len = j - i + 1;
        int64_t current_cost = a[i] * int64_t(n - len);
        cost = std::min(cost, current_cost);
        i = j + 1;
    }


    std::cout << cost << std::endl;
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



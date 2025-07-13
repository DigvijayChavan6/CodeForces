#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    std::string s = "";
    int n = 0;
    std::cin >> n;
    
    std::vector<int> array(n, 0);
    std::vector<int> prefix_min(n, 0);
    std::vector<int> suffix_max(n, 0);


    for(int i = 0; i < n; i++){
        std::cin >> array[i];
    }
    
    prefix_min[0] = array[0];
    suffix_max[n - 1] = array[n - 1];

    for(int i = 1; i < n; i++){
        prefix_min[i] = std::min(prefix_min[i - 1], array[i]);
    }
    for(int i = n - 2; i >= 0; i--){
        suffix_max[i] = std::max(suffix_max[i + 1], array[i]);
    }

    for(int i = 0; i < n; i++) {
        if (prefix_min[i] == array[i] || suffix_max[i] == array[i]) {
            s += std::to_string(1);
        } else {
            s += std::to_string(0);
        }
    }

    std::cout << s << std::endl;
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
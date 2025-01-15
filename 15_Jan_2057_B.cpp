#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    std::map<int, int> cnt;
    std::vector<int> data;
    int n, k;
    std::cin >> n >> k;

    for(int i = 0; i < n; ++i){
        int x;
        std::cin >> x;
        cnt[x]++;
    }


    for(auto [x, c] : cnt){
        data.push_back(c);
    }

    std::sort(data.begin(), data.end());

    int ans = data.size();

    for(int i = 0; i < data.size()-1; ++i){
        if(k >= data[i]){
            k -= data[i];
            ans--;
        }
    }

    std::cout << ans << std::endl;
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
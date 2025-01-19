#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void getCnt(int &ans, std::vector<int> &vals) {
    int cnt = 0;
    for (int i = 1; i <= 3; i++) {
        if(vals[i] + vals[i+1] == vals[i+2]){
            cnt++;
        }
    }
    ans = std::max(ans, cnt);
}

void solve() {
    
    std::vector<int> vals(6 ,0);
    for (int i = 1; i <= 5; i++) {
        if(i == 3) {
            continue;
        }
        std::cin >> vals[i];
    }
    
    int ans = 1, a = vals[1] + vals[2], b = vals[4] - vals[2];

    vals[3] = a;
    getCnt(ans, vals);

    vals[3] = b;
    getCnt(ans, vals);

    std::cout << ans << "\n";
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
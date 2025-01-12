#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::string path;
    std::cin >> path;

    std::vector<int> rowsum(m, 0);
    std::vector<int> colsum(n, 0);
    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            std::cin >> grid[i][j];
            rowsum[i] += grid[i][j];
            colsum[j] += grid[i][j];
        }
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
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n+1, std::vector<int>(m+1));

    for(int i = 1; i <= n; i++){
        a[i][0] = i;
    }

    for (int i = 1; i <= n; i++) {
       for(int j = 1; j <= m; j++) {
           std::cin >> a[i][j];
       }
    }
    

    std::sort(a.begin(), a.end(), [&](std::vector<int> &x, std::vector<int> &y) {
        return x[1] < y[1];
    });
    g

    int t = -1;
    for (int i = 1; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] > a[i+1][j]) {
                std::cout << t << "\n";
                return;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        std::cout << a[i][0] << " ";
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
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

bool solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<int> b(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }


    int cnt = 0;
    int diff = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            cnt++;
            diff = b[i]-a[i];
        }
        if(cnt >= 2){
            return false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i] && abs(a[i] - b[i]) < diff) {
            return false;
        }
    }

    return true;
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        if(!solve()){
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
        }
    }
    
    return 0;
}
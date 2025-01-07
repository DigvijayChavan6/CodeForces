#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> v(n);

    long long sum = 0;

    for(int i = 0; i < n; ++i){
        std::cin >> v[i];
        sum += v[i];
    }

    if(sum % n != 0){
        std::cout << "NO" << std::endl;
        return ;
    }

    long long avg = sum / n;

    for(int i = 1; i < n-1; ++i){
        if(v[i-1] == avg && v[i+1] == avg){
            continue;
        }
        if(v[i-1] < avg){
            v[i+1] -= avg - v[i-1];
            v[i-1] = avg;
        }
        else{
            v[i+1] += v[i-1] - avg;
            v[i-1] = avg;
        }
    }

    for(int i = 0; i < n; ++i){
        if(v[i] != avg){
            std::cout << "NO" << std::endl;
            return ;
        }
    }

    std::cout << "YES" << std::endl;
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
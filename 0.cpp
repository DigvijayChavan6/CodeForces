#include<iostream>

using namespace std;

int main(){
    int t = 0;

    cin >> t;

    while(t--){

    }
    
    return 0;
}


#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::cout << std::max(n, m) + 1 << "\n";
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
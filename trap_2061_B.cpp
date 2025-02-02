#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;
    
    std::vector<int> data(n, 0);
    for(int i = 0; i < n; i++){
        std::cin >> data[i];
    }
    std::sort(data.begin(), data.end());

    int a = -1, b = a, c = -1, d = -1;

    for(int i = 0; i < n-1; i++){
        if(data[i] == data[i+1]){
            a = data[i];
            b = a;
            data[i] = data[i+1] = -1;
            break;
        }
    }

    for(int v : data){
        if(v >= 0){
            if(c == -1){
                c = v;
                continue;
            }
            if(d == -1){
                d = v;
                break;
            }
        }
    }

    if(a == -1){
        std::cout << a << std::endl;
        return;
    }

    std::cout << a << " " << b << " " << c << " " << d << std::endl;
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
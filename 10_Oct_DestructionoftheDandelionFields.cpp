#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<int> odd;
    std::vector<int> even;

    i64 answer = 0;

    for(int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        if (x & 1) {
            odd.push_back(x);
        } else {
            even.push_back(x);
            answer += x;
        }
    }

    std::sort(odd.rbegin(), odd.rend());
    std::sort(even.rbegin(), even.rend());

    if(odd.size() == 0){
        std::cout << odd.size() << "\n";
        return;
    }

    int size = (int)odd.size()/2;
    if((int)odd.size() & 1) {
        size++;
    }

    for(int i = 0; i < size; i++) {
        answer += odd[i];
    }

    std::cout << answer << "\n";
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
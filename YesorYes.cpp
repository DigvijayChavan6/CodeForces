#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
// using u128 = unsigned __int128;

void solve() {
    std::string s;
    std::cin >> s;
    
    std::string ans;
    ans.push_back(s[0]);

    for(int i = 1; i < s.size(); i++) {
        int c = s[i];
        if(c == 'Y') {
            if(ans.back() == 'Y') {
                ans.push_back('Y');
            }
        }else{
            if(ans.back() == 'Y') {
                ans = "Y";
            }
        }
    }

    if(ans.size() == 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
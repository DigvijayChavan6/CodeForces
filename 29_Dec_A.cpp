#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 4;
    for (int i = 0; i + 3 < n; i++) {
        string t = "2026";
        int cost = 0;
        for (int j = 0; j < 4; j++) {
            if (s[i + j] != t[j]) cost++;
        }
        ans = min(ans, cost);
    }

    bool has25 = false;
    for (int i = 0; i + 3 < n; i++) {
        if (s.substr(i, 4) == "2025") {
            has25 = true;
            break;
        }
    }

    if (!has25) {
        ans = min(ans, 0);
    } else {
        ans = min(ans, 1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int answer = 0;

    for (int layers = 1; layers <= 25; layers++) {
        long long white1 = 0, dark1 = 0;
        long long white2 = 0, dark2 = 0;

        long long size = 1;

        for (int i = 1; i <= layers; i++) {
            if (i % 2 == 1) {
                white1 += size;
                dark2 += size;
            } else {
                dark1 += size;
                white2 += size;
            }
            size *= 2;
        }

        bool ok1 = (white1 <= a && dark1 <= b);
        bool ok2 = (white2 <= a && dark2 <= b);

        if (ok1 || ok2) {
            answer = layers;
        } else {
            break;
        }
    }

    cout << answer << '\n';
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

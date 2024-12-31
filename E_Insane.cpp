#include <iostream>
#include <cmath>
using namespace std;


long long log_base_k(long long value, long long k) {
    return log(value) / log(k);
}

long long countPairs(long long k, long long a, long long b, long long p, long long q) {
    long long count = 0;
    for (long long x = a; x <= b; ++x) {
        if (x > q) break; 
        
        long long n_min = ceil(log_base_k((double)p / x, k));
        long long n_max = floor(log_base_k((double)q / x, k));
        
        if (n_min <= n_max) {
            count += (n_max - n_min + 1);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long k, a, b, p, q;
        cin >> k >> a >> b >> p >> q;
        cout << countPairs(k, a, b, p, q) << endl;
    }
    return 0;
}

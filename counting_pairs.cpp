#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long countInterestingPairs(vector<long long> &data, long long maximum, long long minimum) {
    long long count = 0;
    sort(data.begin(), data.end());
    int n = data.size();

    for (int i = 0; i < n - 1; ++i) {
        long long small = minimum - data[i];
        long long big = maximum - data[i];

        auto lower = lower_bound(data.begin() + i + 1, data.end(), small);
        auto upper = upper_bound(data.begin() + i + 1, data.end(), big);

        count += (upper - lower);
    }

    return count;
}

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n, x, y, sum = 0;
        cin >> n >> x >> y;

        vector<long long> data(n);
        for (long long i = 0; i < n; ++i) {
            cin >> data[i];
            sum += data[i];
        }

        long long maximum = sum - x;
        long long minimum = sum - y;

        cout << countInterestingPairs(data, maximum, minimum) << endl;
    }

    return 0;
}

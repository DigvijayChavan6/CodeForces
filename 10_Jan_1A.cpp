#include <iostream>
using namespace std;

int main()
{
    int n, m, a;
    cin >> n >> m >> a;

    long long tiles_along_length = (n + a - 1) / a;
    long long tiles_along_width = (m + a - 1) / a;

    long long total_tiles = tiles_along_length * tiles_along_width;

    cout << total_tiles << endl;

    return 0;
}

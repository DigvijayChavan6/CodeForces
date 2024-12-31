#include <iostream>
#include <unordered_map>

using namespace std;

void printArr(int a[], int n) {
    unordered_map<int, int> freq;
    int maxFreq = 0, mode = 0;

    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
        if (freq[a[i]] > maxFreq) {
            maxFreq = freq[a[i]];
            mode = a[i];
        } else if (freq[a[i]] == maxFreq && a[i] < mode) {
            mode = a[i];
        }
        cout << mode << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        printArr(a, n);
    }
    return 0;
}

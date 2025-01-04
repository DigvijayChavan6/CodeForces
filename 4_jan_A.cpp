#include<iostream>

using namespace std;

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        int n, m;

        cin >> n >> m;
        cout << max(m, n) + 1 << endl;
    }
    
    return 0;
}
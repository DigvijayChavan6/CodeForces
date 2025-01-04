#include<iostream>

using namespace std;

void solve(){
    int l, r;
    cin >> l >> r;

    int a = 0, b = 0, c = 0;

    for(int i = 29; i >= 0; --i){
        if((l^r) >> i  & 1){
            a |= 1 << i;
            b |= (1 << i) - 1;
            break;
        }else{
            a |= l & (1 << i);
            b |= l & (1 << i);
        }
    }

    c = l;

    while(a == c || b == c){
        c++;
    }

    cout << a << " " << b << " " << c << "\n";
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        solve();
    }
    
    return 0;
}
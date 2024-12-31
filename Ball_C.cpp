#include<iostream>

using namespace std;

int getMax(int m, int a, int b, int c){
    int max = 0;
    int r1 = m, r2 = m;
    
    max = min(a, m) + min(b, m);

    if(r1 >= a){
        r1 -= a;
    }else{
        r1 = 0;
    }

    if(r2 >= b){
        r2 -= b;
    }else{
        r2 = 0;
    }

    max += min(r1 + r2, c);

    return max;
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        int m = 0, a = 0, b = 0, c = 0;
        cin >> m >> a >> b >> c;

        cout << getMax(m, a, b, c) << endl;
    }
    
    return 0;
}
#include<iostream>

using namespace std;

long long getNum(long long x){
    string s = to_string(x);
    size_t pos = s.find("33");
    
    if (pos != string::npos) {
        s.erase(pos, 2);
        x = stoll(s);
    } 
    return x;
}

bool possible(long long n){
    
    while(n >= 33){
        if(n % 33 == 0){
            return true;
        }else{
            long long t = getNum(n);
            if(n != t){
                n = t;
            }else{
                n -= 33;
            }
        }
    }

    return n == 0 ? true : false;
}

int main(){
    long long t = 0;
    cin >> t;

    while(t--){
        long long n = 0;
        cin >> n;

        if(possible(n)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}
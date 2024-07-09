#include<iostream>
using namespace std;

bool isLargeSum(string x){
    int n=x.size();
    if(x[0]!='1' || x[n-1]=='9')return false;
    int i=1;
    while(i<=n-2){
        if(x[i] == '0')return false;
        i++;
    }
    return true;
}

int main(){
    long long t;
    cin>>t;
    while(t--){
        string x;
        cin>>x;
        if(isLargeSum(x)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}

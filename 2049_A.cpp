#include<iostream>
#include<deque>

using namespace std;

int getNum(deque<int> &q, int n){
    while(!q.empty() && q.back() == 0){
        q.pop_back();
    }
    while(!q.empty() && q.front() == 0){
        q.pop_front();
    }
    
    if(q.empty()){
        return 0;
    }

    while(!q.empty()){
        if(q.back() == 0){
            return 2;
        }
        q.pop_back();
    }

    return 1;
}

int main(){

    int t = 0;

    cin >> t;

    while(t--){
        deque<int> q;
        int n = 0;
        int val = 0;

        cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> val;
            q.push_back(val);
        }

        cout << getNum(q, n) << endl;
    }

    return 0;
}
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

int getAliceScore(unordered_map<int, int> &m){
    vector<int> v;
    int coins = 0;

    for(auto p : m){
        v.push_back(p.second);
    }

    sort(v.begin(), v.end(), greater<int>());

    for(int i = 0; i < v.size(); ++i){
        int val = v[i];
        if(val == 1){
            coins += 2;
            ++i;
        }else{
            coins += 1;
        }
    }

    return coins;
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        int n = 0;

        cin >> n;

        unordered_map<int, int> m;

        for(int i = 0; i < n; i++){
            int x = 0;

            cin >> x;

            m[x]++;
        }

        cout << getAliceScore(m) << endl;
    }
    
    return 0;
}
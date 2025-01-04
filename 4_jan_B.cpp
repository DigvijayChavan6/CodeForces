#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int getSolution(unordered_map<int, int> &mp, int k){
    vector<int> v;
    for(auto p : mp){
        v.push_back(p.second);
    }

    sort(v.begin(), v.end());

    int answer = v.size();

    for(int i = 0; i < v.size(); ++i){
        if(v[i] <= k){
            k -= v[i];
            answer--;
        }else{
            break;
        }
    }

    return answer ? answer : 1;
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        int n, k, t;
        cin >> n >> k;
        
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i){
            cin >> t;
            mp[t]++;
        }

        cout << getSolution(mp, k) << endl;
    }
    
    return 0;
}
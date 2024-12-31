#include<iostream>

using namespace std;

string getStr(string &s){
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p'){
            answer = "q" + answer;
        }else if(s[i] == 'q'){
            answer = "p" + answer;
        }else{
            answer = s[i] + answer;
        }
    }
    return answer;
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        string s = "";
        cin >> s;
        cout << getStr(s) << endl;
    }
    
    return 0;
}
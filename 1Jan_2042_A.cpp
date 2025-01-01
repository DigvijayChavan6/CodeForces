#include<iostream>
#include<algorithm>

using namespace std;

int getMin(int arr[], int n, int k){
    sort(arr, arr + n);

    int sum = 0;
    
    for(int i = n-1; i >= 0; --i){
        if(sum + arr[i] == k){
            return 0;
        }else if(sum + arr[i] > k){
            return k - sum;
        }else{
            sum += arr[i];
        }
    }

    

    return k - sum;
}

int main(){
    int t = 0;

    cin >> t;

    while(t--){
        int n = 0, k = 0;
        cin >> n >> k;

        int arr[n];

        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }

        cout << getMin(arr, n, k) << endl;
    }
    
    return 0;
}
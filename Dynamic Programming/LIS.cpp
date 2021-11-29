//
// Created by Gaurav Hoskote on 29/11/2021.
// Program for longest increasing subsequence
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n), lis(n,1);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[j] <= arr[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout<<lis[i]<<endl;
    }

    return 0;
}
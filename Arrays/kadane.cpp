// Given an array that consists of positive and negative elements write a function to find the maximum contiguous SubArray


#include <bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    int sum = 0,ms=INT_MIN;
    bool b = false;
    for(int i = 0; i < A.size(); i++){
        sum = max(A[i],sum+A[i]);
        ms = max(sum,ms);
    }
    return ms;
}


int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){cin>>arr[i];}
    int maxsum = maxSubArray(arr);
    cout<<maxsum<<endl;
    return 0;
}



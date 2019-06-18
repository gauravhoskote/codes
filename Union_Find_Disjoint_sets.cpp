//  Created by Gaurav Hoskote on 17/06/2019.
//  Copyright © 2019 Gaurav Hoskote. All rights reserved.
//

#include<bits/stdc++.h>

using namespace std;

int arr[100000];
int size[100000];

void initialize(int n){
    
    for(int i = 0; i <= n; i++){
        arr[i] = i;
        size[i] = 1;
    }
    
}


int find(int i){
    while(arr[i] != i){
        arr[i] = arr[arr[i]];
        i = arr[i];
    }
    return i;
}

void unify(int x, int y){
    int root1 = find(x);
    int root2 = find(y);
    if(root1 == root2){
        return;
    }
    if(size[root1] < size[root2] ){
        arr[root1] = root2;
        size[root2] = size[root2]+size[root1];
    }else{
        arr[root2] = root1;
        size[root1] = size[root1]+size[root2];
    }
    
}

void display(int n){
    
    for(int i = 0; i <= n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}

bool isconnected(int x, int y){
    int root1 = find(x);
    int root2 = find(y);
    return root1 == root2;
}


int main(){
    int n = 10;
    initialize(n);// initializing arrays
    display(n);// display initial state of arrays
    // Performing unify operations
    unify(0,1);
    display(n);
    unify(1,2);
    display(n);
    unify(2,3);
    display(n);
    unify(3,4);
    display(n);
    unify(5,6);
    display(n);
    unify(6,7);
    display(n);
    unify(8,7);
    display(n);
    unify(9,8);
    display(n);
    unify(1,5);
    display(n);
    // Size of element.... The size of the root should be no. of elements in that group
    for(int i = 0; i < 10; i++){
        cout<<size[i]<<endl;
    }
    // Every number should be Connected
    for(int i = 0; i <= 8; i++){
        for(int j = i+1; j < 10; j++){
            if(isconnected(i,j)){
                cout<<"Connected"<<endl;
            }else{
                cout<<"Not Connected"<<endl;
            }
        }
    }
    return 0;
}





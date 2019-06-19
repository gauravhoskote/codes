#include <bits/stdc++.h>
using namespace std;

void buildsegtree(int* arr, int* tree, int l, int r, int n){
    if(l > r){
        return;
    }
    if(l == r){
        tree[n] = arr[l];
        return;
    }
    buildsegtree(arr, tree, l, (l+r)/2, 2*n);
    buildsegtree(arr, tree, ((l+r)/2)+1, r, (2*n)+1);
    tree[n] = tree[2*n] + tree[2*n + 1];// This expression changes according to need
}

int query(int* tree, int n, int a, int b, int i, int j){ //1, 1, n, l, r
    if(a > b || a > j || b < i){
        return 0;
    }
    if(a >= i && b <= j){
        return tree[n];
    }
    int q1 = query(tree, 2*n, a, (a+b)/2, i, j);
    int q2 = query(tree, 2*n + 1, ((a+b)/2) + 1, b, i, j);
    return q1 + q2;
    
}

void update(int* tree,int* arr, int n, int a, int b, int val, int newval){
    if(a == b){
        arr[val] = newval;
        tree[n] = newval;
    }else{
        int mid = (a + b)/2;
        if(a <=val && val <= b){
            update(tree, arr, 2*n, a, (a+b)/2,val, newval );
        }else{
            update(tree, arr, 2*n+1, ((a+b)/2)+1, b, val, newval );
        }
        tree[n] = tree[2*n] + tree[2*n + 1];
    }
}



int main() {
	int n; cin>>n;
	int arr[n+1];
	for(int i = 1; i <= n; i++){
	    cin>>arr[i];
	}
	int tree[2*n];
	buildsegtree(arr,tree,1,6,1);
	cout<<query(tree,1,1,6,2,6)<<endl;
	update(tree, arr, 1, 1, 6, 1, 6);
	for(int i = 1; i <= n; i++){
	    cout<<arr[i];
	}	
	return 0;
}

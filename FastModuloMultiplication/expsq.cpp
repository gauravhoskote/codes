#include <bits/stdc++.h>
using namespace std;
#define Mod 1000000007
int main() {
	long long int b,e;
	cin>>b>>e;
	long long int res = 1;
	while(e > 0){
	   if(e%2 == 1){
	      res = (res * b)%Mod;
	   }
	   b = (b*b)%Mod;
	   e = e/2;
	}
	cout<<res<<endl;
	return 0;    
}

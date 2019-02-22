//  main.cpp
//  Created by Gaurav Hoskote on 04/02/2019.
//  Copyright © 2019 Gaurav Hoskote. All rights reserved.
//

#include "bits/stdc++.h"
#include "vec.hpp"
using namespace std;

int main()
{
    Vector<int> a(3);
    Vector<int> b(3);
    cout<<"A"<<endl;
    for(int i = 0; i < a.size(); i++){
        a[i] = i+1;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"B"<<endl;
    for(int i = 0; i < b.size(); i++){
        b[i] = a[i]+3;
        cout<<b[i]<<" ";
    }
    cout<<endl;
    cout<<"C = A + B"<<endl;
    Vector<int> c = a + b;
    for(int i = 0; i < b.size(); i++){
        cout<<c[i]<<" ";
    }
    c = b-a;
    cout<<endl;
    cout<<"C = B - A"<<endl;
    for(int i = 0; i < b.size(); i++){
        cout<<c[i]<<" ";
    }
    c = b /a;
    cout<<endl;
    cout<<"C = B / A"<<endl;
    for(int i = 0; i < b.size(); i++){
        cout<<c[i]<<" ";
    }
    c = b*a;
    cout<<endl;
    cout<<"C = B * A"<<endl;
    for(int i = 0; i < b.size(); i++){
        cout<<c[i]<<" ";
    }
    c += b;
    cout<<endl;
    cout<<"C += B"<<endl;
    for(int i = 0; i < b.size(); i++){
        cout<<c[i]<<" ";
    }
    cout<<endl<<endl;
    Matrix<int> m(100,2,5);
    Matrix<int> n(2,100,2);
    cout<<"M = 3x2";
    cout<<endl;
    for(int i = 0; i < m.nrow(); i++){
        for(int j = 0; j < m[0].size(); j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"N => 2x3";
    cout<<endl;
    for(int i = 0; i < n.nrow(); i++){
        for(int j = 0; j < n[0].size(); j++){
            cout<<n[i][j]<<" ";
        }
        cout<<endl;
    }
    clock_t t;
    t = clock();
    Matrix<int> s = m*n;
    t = clock()-t;
    double tt = ((double)t)/CLOCKS_PER_SEC;
    cout<<"Time Taken : "<<tt<<endl;
    cout<<"S = M*N => 3x3";
    cout<<endl;
    for(int i = 0; i < s.nrow(); i++){
        for(int j = 0; j < s.ncol(); j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    m *= n;
    cout<<"M *= N => 3x3";
    cout<<endl;
    for(int i = 0; i < m.nrow(); i++){
        for(int j = 0; j < m.ncol(); j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

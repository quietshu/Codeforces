/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/04/25 23:31:52
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int n, a[1000], n1, n2, pos1, pos2, pos3;

int main(){
    cin >> n;
    rep(i, n){
        cin >> a[i];
        n1 += (a[i] > 0);
        n2 += (a[i] < 0);
    }
   
    cout << 1 << " ";
    rep(i, n)
        if(a[i] < 0){
            pos1 = i;
            cout << a[i];
            break;
        }
    cout << endl;

    if(n1 == 0){
        cout << 2 << " ";
        for(int i = 0, j = 1; i < 2; ++j){
            if(j != pos1 && a[j] < 0){
                cout << a[j] << " ";
                ++i;
                if(i == 1)pos2 = j;
                else pos3 = j;
            }
        }
    }
    else{
        cout << 1 << " ";
        rep(j, n) if(a[j] > 0){
            cout << a[j];
            pos2 = j;
            break;
        }
    }
    cout << endl;

    cout << n - (pos1 > 0) - (pos2 > 0) - (pos3 > 0) << " ";
    rep(i, n)
        if(i != pos1 && i != pos2 && i != pos3) cout << a[i] << " ";
    return 0;
}

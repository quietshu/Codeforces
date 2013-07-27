/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/07/24 23:31:40
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

int n, m, k;
char a[4];

int main(){
    cin >> n;
    a[0] = '$';
    a[3] = getchar();
    a[3] = getchar();
    while(a[3] == 'a' || a[3] == 'b'){
        if(k % n == 0)
            m += (a[0] == a[1] && a[1] == a[2]);
        k++;
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[3];
        a[3] = getchar();
    }
    cout << m << endl;
    return 0;
}

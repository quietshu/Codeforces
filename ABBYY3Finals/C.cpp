/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/07/17 23:48:00
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

int n, f[1000010];

int calc(int n){
    int t = n, ret = 10000000, p = 0, q = 0;
    while(t){
        if(t % 10 > 0 && (f[n - t % 10] + 1 < ret || (f[n - t % 10] + 1 == ret && t % 10 > p))){
            ret = min(ret, f[n - t % 10] + 1);
            p = t % 10;
        }
        q = max(q, t % 10);
        t /= 10;
    }
    if(p != q)
        cout << n << '-' << p << endl;
    return ret;
}

int main(){
    int las = 1;
    cin >> n;
    rep(i, n){
        f[i] = calc(i);
        if(i > 1 && f[i] != f[i - 1]){
            cout << i - las + 1 << endl;
            las = i;
        }
    }
    return 0;
}

/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : D.cpp
*	Creation Time : 2013/04/13 21:28:43
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, len = 1;

void solve(){
    rep(i, n)
        printf("%d ", min(n, i + len));
    puts("");
    len <<= 1;
    len = min(len, n);
}

int main(){
    cin >> n >> k;
    rep(i, k) solve();
    return 0;
}

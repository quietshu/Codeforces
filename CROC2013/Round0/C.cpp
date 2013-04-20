/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : C.cpp
*	Creation Time : 2013/04/13 20:41:15
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k;
long long ip[100010][4], tmp;
set<long long> s;

bool check(int bit){
    s.clear();
    tmp = ~((1ll << (33 - bit)) - 1);
    rep(i, n){
        s.insert(((((((ip[i][0] << 8) + ip[i][1]) << 8) + ip[i][2]) << 8) + ip[i][3]) & tmp);
        if(s.size() > k)
            return 0;
    }
    return s.size() == k;
}

int main(){
    cin >> n >> k;
    rep(i, n)
        scanf("%I64d.%I64d.%I64d.%I64d", &ip[i][0], &ip[i][1], &ip[i][2], &ip[i][3]);
    rep(i, 33)
        if(check(i - 1)){
            printf("%I64d.%I64d.%I64d.%I64d\n", (tmp >> 24) & 255, (tmp >> 16) & 255, (tmp >> 8) & 255, tmp & 255);
            return 0;
        }
    puts("-1");
    return 0;
}

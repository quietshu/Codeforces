/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : E.cpp
*   Creation Time : 2013/04/26 00:11:12
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

int k, a[1000010], pn;
int prime[10000010], power[1000010];
bool inp[10000010];

void init(){
    for(int i = 2; i <= 1e7; ++i){
        if(!inp[i])
            prime[++pn] = i;
        for(int j = 1; j <= pn && i * prime[j] <= 1e7; ++j){
            inp[i * prime[j]] = 1;
            if(i % prime[j] == 0)
                break;
        }
    }
}

int main(){
    init();
    cin >> k;
    rep(i, k)
        scanf("%d", &a[i]);
    rep(i, pn){
        int tmp = prime[i];
        while(tmp <= 1e7){
            tmp *= prime[i];
        }
    }
    return 0;
}

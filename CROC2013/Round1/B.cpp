/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/04/15 23:47:06
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
#define MAXN 100010
using namespace std;

int n, m, deg[MAXN];

int main(){
    cin >> n >> m;
    int x, y;
    rep(i, m){
        scanf("%d%d", &x, &y);
        deg[x]++;
        deg[y]++;
    }
    int one = 0, two = 0;
    rep(i, n)
        if(deg[i] == 2) ++two;
        else if(deg[i] == 1) ++one;
    if(one + two == n && one == 2){
        puts("bus topology");
        return 0;
    }
    if(one + two == n && one == 0){
        puts("ring topology");
        return 0;
    }
    if(one == n - 1){
        puts("star topology");
        return 0;
    }
    puts("unknown topology");
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/07/27 18:08:25
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
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int n, m, ans, a[1001][1001], p[1001][1001];

void read(int &n){
    char c = getchar();
    n = 0;
    while(c < '0' || c > '9')
        c = getchar();
    while(c >= '0' && c <= '9'){
        n = n * 10 + c - '0';
        c = getchar();
    }
}

int main(){
    cin >> n >> m;
    rep(i, n)
        rep(j, m){
            read(a[i][j]);
            rep(k, j - 1){
                ans = max(ans, min(p[k][j], min(a[i][k], a[i][j])));
                p[k][j] = max(p[k][j], min(a[i][k], a[i][j]));
            }
        }
    cout << ans << endl;
    return 0;
}

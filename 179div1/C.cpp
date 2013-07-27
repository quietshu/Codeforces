/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : #179
*	Creation Time : 2013/04/11 23:01:50
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define MAXN 100
#define MOD 1000000007
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, p, w[MAXN];
int f[MAXN][MAXN][2], g[MAXN][MAXN][2];
long long C[MAXN][MAXN];

void calc(int i, int j, int s){
    if(s){
        if(i + j == 0){
            f[i][j][1] = 0;
            g[i][j][1] = 1;
            return;
        }
        if(f[i][j][1]) return;
        f[i][j][1] = MOD;
        int tmp[MAXN], tn = 0;
        for(int x = 0; x <= p - j; ++x)
            for(int y = 0; y <= n - i - (p - j); ++y)
                if(x + y && x * 50 + y * 100 <= k){
                    if(!f[i + x + y][j + x][0]) tmp[++tn] = 
                    calc(i + x + y, j + x, 0);
                    if(f[i][j][1] > f[i + x + y][j + x][0] + 1)
                        f[i][j][1] = f[i + x + y][j + x][0] + 1,
                        g[i][j][1] = (long long)g[i + x + y][j + x][0] * C[p - j][x] % MOD * C[n - i - j][y] % MOD;
                    else if(f[i][j][1] == f[i + x + y][j + x][0] + 1)
                        g[i][j][1] = (g[i][j][1] + (long long)g[i + x + y][j + x][0] * C[p - j][x] % MOD * C[n - i - p + j][y] % MOD) % MOD;
                }
        for(int x = 0; x <= p - j; ++x)
            for(int y = 0; y <= n - i - (p - j); ++y)
                if(x + y && x * 50 + y * 100 <= k){
                    if(f[i + x + y][j + x][0] == MOD)f[i + x + y][j + x][0] = 0,
                    calc(i + x + y, j + x, 0);
                }
        return;
    }
    if(i + j == 0){
        f[i][j][0] = 0;
        g[i][j][0] = 1;
        return;
    }
    if(f[i][j][0]) return;
    f[i][j][0] = MOD;
    for(int x = 0; x <= j; ++x)
        for(int y = 0; y <= i - j; ++y)
            if(x + y && x * 50 + y * 100 <= k){
                calc(i - x - y, j - x, 1);
                if(f[i][j][0] > f[i - x - y][j - x][1] + 1)
                    f[i][j][0] = f[i - x - y][j - x][1] + 1,
                    g[i][j][0] = (long long)g[i - x - y][j - x][1] * C[j][x] % MOD * C[i - j][y] % MOD;
                else if(f[i][j][0] == f[i - x - y][j - x][1] + 1)
                    g[i][j][0] = (g[i][j][0] + (long long)g[i - x - y][j - x][1] * C[j][x] % MOD * C[i - j][y] % MOD) % MOD;
            }
    for(int x = 0; x <= j; ++x)
        for(int y = 0; y <= i - j; ++y)
            if(x + y && x * 50 + y * 100 <= k){
                if(f[i - x - y][j - x][1] == MOD)f[i - x - y][j - x][1] = 0,
                calc(i - x - y, j - x, 1);
            }
}

void init(){
    for(int i = 0; i < MAXN; ++i)
        for(int j = 0; j <= i; ++j)
            C[i][j] = (!j || i == j) ? 1 : (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
}

int main(){
    init();
    scanf("%d%d", &n, &k);
    rep(i, n) cin >> w[i], p += (w[i] == 50);
    calc(n, p, 0);
    if(f[n][p][0] == MOD) cout << -1 << endl;
    else cout << f[n][p][0] << endl;
    cout << g[n][p][0] << endl;
    return 0;
}

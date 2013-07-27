/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/06/08 00:38:12
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
#define MAXA 1000010
#define MOD 1000000007
using namespace std;

int n, a[MAXN], b[MAXN], f[MAXN], num[MAXA], pr[MAXN], top[MAXA];
pair<int, int> c[MAXN];

void add(int v, int x){
    for(; v < MAXA; v += v & -v)
        num[v] = (num[v] + x) % MOD;
}

int get(int v){
    int res = 0;
    for(; v; v -= v & -v)
        res = (res + num[v]) % MOD;
    return res;
}

int main(){
    scanf("%d", &n);
    rep(i, n)
        scanf("%d", &b[i]), c[i] = mp(b[i], i), pr[i] = top[b[i]], top[b[i]] = i;
    sort(c + 1, c + 1 + n);
    rep(i, n)
        a[c[i].second] = i;
    rep(i, n){
        f[i] = get(b[i]);
        f[i] = ((long long)b[i] * f[i] % MOD + f[i] + b[i]) % MOD;
        f[i] = (f[i] - f[pr[i]]) % MOD;
        add(b[i] + 1, f[i]);
    }
    cout << f[n] << endl;
    return 0;
}

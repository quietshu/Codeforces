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
#define MAXN 100010
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, k, L, R, a[MAXN];
int l[MAXN], r[MAXN], num[MAXN];
long long d[MAXN], tum[MAXN];

void add(int v, int p){
    for(; v <= m; v += v & -v)
        num[v] += p;
}

void add2(int v, long long p){
    for(; v <= n; v += v & -v)
        tum[v] += p;
}

int sum(int v){
    int ret = 0;
    for(; v; v -= v & -v)
        ret += num[v];
    return ret;
}

long long sum2(int v){
    long long ret = 0;
    for(; v; v -= v & -v)
        ret += tum[v];
    return ret;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) scanf("%d%d%lld", &l[i], &r[i], &d[i]);
    rep(i, k){
        scanf("%d%d", &L, &R);
        add(L, 1);
        add(R + 1, -1);
    }
    long long tmp;
    rep(i, m){
        tmp = d[i] * sum(i);
        add2(l[i], tmp);
        add2(r[i] + 1, -tmp);
    }
    rep(i, n)
        printf("%lld ", sum2(i) + a[i]);
    return 0;
}

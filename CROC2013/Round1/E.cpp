/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : E.cpp
*   Creation Time : 2013/04/16 00:29:47
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

struct node{
    int l, r, c[2], mark, tag;
} t[MAXN * 2];

int n, m, num = 1, a[MAXN], b[MAXN], X[MAXN], Y[MAXN], K[MAXN];

void build(int v, int l, int r){
    t[v].l = l;
    t[v].r = r;
    t[v].mark = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(t[v].c[0] = ++num, l, m);
    build(t[v].c[1] = ++num, m + 1, r);
}

void pushdown(int n){
    int l = t[n].c[0], r = t[n].c[1];
    if(t[n].tag){
        t[l].tag = t[l].mark = t[n].tag;
        t[r].tag = t[r].mark = t[n].tag;
        t[n].tag = 0;
    }
}

void modify(int n, int l, int r, int v){
    if(t[n].l == l && t[n].r == r){
        t[n].mark = t[n].tag = v;
        return;
    }
    pushdown(n);
    int m = (t[n].l + t[n].r) >> 1;
    if(r <= m)
        modify(t[n].c[0], l, r, v);
    else if(l > m)
        modify(t[n].c[1], l, r, v);
    else
        modify(t[n].c[0], l, m, v), modify(t[n].c[1], m + 1, r, v);
}

int query(int n, int x){
    if(t[n].l == x && t[n].r == x)
        return t[n].mark;
    pushdown(n);
    int m = (t[n].l + t[n].r) >> 1;
    return query(t[n].c[x > m], x);
}

int main(){
    cin >> n >> m;
    rep(i, n) scanf("%d", &a[i]);
    rep(i, n) scanf("%d", &b[i]);
    build(1, 1, n);
    int opt, x, cmd;
    rep(i, m){
        scanf("%d%d", &opt, &x);
        if(opt == 1){
            scanf("%d%d", &Y[i], &K[i]);
            modify(1, Y[i], Y[i] + K[i] - 1, i);
            X[i] = x;
        }
        else{
           cmd = query(1, x);
           if(!cmd)
               printf("%d\n", b[x]);
           else
               printf("%d\n", a[x - Y[cmd] + X[cmd]]);
        }
    }
    return 0;
}

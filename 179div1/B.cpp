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
#define MAXN 1000
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const long long inf = 100000000000000ll;
int n, d[MAXN], P;
long long g[MAXN][MAXN], ans[MAXN];
bool del[MAXN], vst[MAXN];
long long dis[MAXN], dis2[MAXN];
int que[MAXN * 20], p;

void bfs(int v){
    for(int i = 1; i <= n; ++i) dis[i] = inf, vst[i] = 0;
    dis[v] = 0; vst[v] = 1;
    que[p = 1] = v;
    for(int i = 1; i <= p; ++i){
        for(int j = 1; j <= n; ++j)
            if(!del[j] && g[que[i]][j] && g[que[i]][j] + dis[que[i]] < dis[j]){
                dis[j] = g[que[i]][j] + dis[que[i]];
                if(!vst[j])
                    que[++p] = j;
                vst[j] = 1;
            }
        vst[que[i]] = 0;
    }
    for(int i = 1; i <= n; ++i) if(!del[i] && dis[i] < inf)
        g[v][i] = dis[i], ans[P] += g[v][i];

    for(int i = 1; i <= n; ++i) dis2[i] = inf, vst[i] = 0;
    dis2[v] = 0; vst[v] = 1;
    que[p = 1] = v;
    for(int i = 1; i <= p; ++i){
        for(int j = 1; j <= n; ++j)
            if(!del[j] && g[que[i]][j] && g[j][que[i]] + dis2[que[i]] < dis2[j]){
                dis2[j] = g[j][que[i]] + dis2[que[i]];
                if(!vst[j])
                    que[++p] = j;
                vst[j] = 1;
            }
        vst[que[i]] = 0;
    }
    for(int i = 1; i <= n; ++i) if(!del[i] && dis2[i] < inf)
        g[i][v] = dis2[i], ans[P] += g[i][v];


    for(int i = 1; i <= n; ++i) if(!del[i])
        for(int j = 1; j <= n; ++j) if(!del[j] && i != j)
            if(!g[i][j] || g[i][j] > dis[j] + dis2[i])
                ans[P] += dis[j] + dis2[i] - g[i][j],
                g[i][j] = dis[j] + dis2[i];
}

int main(){
    scanf("%d", &n);
    rep(i, n) rep(j, n) scanf("%lld", &g[i][j]);
    rep(i, n) scanf("%d", &d[i]), del[d[i]] = 1;
    rep(i, n) if(!del[i])
        rep(j, n) if(!del[j])
            rep(k, n) if(!del[k])
                if(g[i][k] && g[k][j] && (g[i][k] + g[k][j] < g[i][j] || !g[i][j]))
                    g[i][j] = g[i][k] + g[k][j];
    rep(i, n) if(!del[i])
        rep(j, i - 1) if(!del[j])
            ans[n] += g[i][j];
    for(P = n; P; --P){
        ans[P] += ans[P + 1];
        del[d[P]] = 0;
        bfs(d[P]);
    }
    rep(i, n) printf("%lld ", ans[i]); puts("");
    return 0;
}

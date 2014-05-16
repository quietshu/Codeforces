/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/08/17 00:35:40
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

int n, m, d, s[100010], dis[100010], ml[100010], mr[100010];
vector<int> e[100010];
bool hv[100010], ch[100010];

void dfs(int v, int f){
    dis[v] = -1;
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            dfs(e[v][i], v);
            if(hv[e[v][i]])
                dis[v] = max(dis[v], dis[e[v][i]] + 1), hv[v] = 1;
        }
    if(ch[v]){
        hv[v] = 1;
        dis[v] = max(dis[v], 0);
    }
}

void dfs2(int v, int f, int m){
    if(m != -1)
        dis[v] = max(dis[v], m + 1);
    int l = 0;
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            ml[e[v][i]] = max(dis[l] + 1, ml[l]);
            l = e[v][i];
        }
    l = 0;
    for(int i = (int)e[v].size() - 1; i >= 0; --i)
        if(e[v][i] != f){
            mr[e[v][i]] = max(dis[l] + 1, mr[l]);
            l = e[v][i];
        }
    int nxt;
    for(int i = 0; i < e[v].size(); ++i)
        if(e[v][i] != f){
            nxt = max(ml[e[v][i]], mr[e[v][i]]);
            if(m != -1)
                nxt = max(nxt, m + 1);
            else if(ch[v])
                nxt = max(nxt, 0);
            dfs2(e[v][i], v, nxt);
        }
}

int main(){
    cin >> n >> m >> d;
    for(int i = 1; i <= m; ++i)
        scanf("%d", &s[i]), ch[s[i]] = 1;

    int a, b;
    for(int i = 1; i < n; ++i){
        scanf("%d%d", &a, &b);
        e[a].pb(b);
        e[b].pb(a);
    }
    dis[0] = -2;
    dfs(1, 0);
    dfs2(1, 0, -1);
    int cnt = 0;
    for(int i = 1; i <= n; ++i)
        if(dis[i] <= d)
            ++cnt;
    cout << cnt << endl;
    return 0;
}

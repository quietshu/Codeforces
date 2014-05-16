/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/07/27 17:19:12
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

pair<int, int> p[10];
int n, m, x, y, ans, cnt, tmp;
bool row[1010], col[1010], vst[1010];
int canot[1010][1010];

void dfs(int v, int tot){
    if(v > cnt){
        tmp = max(tmp, tot);
        return;
    }
    dfs(v + 1, tot);
    if(!canot[p[v].first][p[v].second] && !row[p[v].first] && !col[p[v].second]){
        canot[p[v].first][p[v].second]++;
        canot[p[v].second][p[v].first]++;
        canot[n + 1 - p[v].second][n + 1 - p[v].first]++;
        if(p[v].first == 1)
            canot[n][p[v].second]++;
        else
            canot[p[v].first][n]++;
        dfs(v + 1, tot + 1);
        canot[p[v].first][p[v].second]--;
        canot[p[v].second][p[v].first]--;
        canot[n + 1 - p[v].second][n + 1 - p[v].first]--;
        if(p[v].first == 1)
            canot[n][p[v].second]--;
        else
            canot[p[v].first][n]--;
    }
}

void search(int x){
    vst[x] = 1;
    vst[n + 1 - x] = 1;
    p[cnt = 1] = mp(1, x);
    p[++cnt] = mp(x, 1);
    p[++cnt] = mp(x, n);
    p[++cnt] = mp(n, x);
    if(x + x <= n){
        p[++cnt] = mp(1, n + 1 - x);
        p[++cnt] = mp(n + 1 - x, 1);
        p[++cnt] = mp(n + 1 - x, n);
        p[++cnt] = mp(n, n + 1 - x);
    }
    tmp = 0;
    dfs(1, 0);
    ans += tmp;
}

int main(){
    cin >> n >> m;
    rep(i, m){
        scanf("%d%d", &x, &y);
        row[x] = 1;
        col[y] = 1;
    }
    for(int i = 2; i < n; ++i)
        if(!vst[i])
            search(i);
    cout << ans << endl;
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/04/16 00:06:36
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

int n, m, num, s[MAXN], t[MAXN], f[MAXN], ans[MAXN];

int father(int i){
    return f[i] == i ? i : f[i] = father(f[i]);
}

struct que{
    int l, r, no;
    bool operator < (const que &q) const{ return l < q.l; }
} q[MAXN];

int k, res[MAXN];

int main(){
    cin >> n >> m;
    rep(i, m)
        scanf("%d%d", &s[i], &t[i]);
    cin >> k;
    rep(i, k)
        scanf("%d%d", &q[i].l, &q[i].r), q[i].no = i;
    sort(q + 1, q + 1 + k);
    for(int i = k, j = k; i >= 1; i = j){
        while(j >= 1 && q[j].l == q[i].l) --j;
        rep(x, n) f[x] = x;
        num = n;
        rep(x, q[i].l - 1) if(father(s[x]) != father(t[x])){
            num--;
            f[father(s[x])] = father(t[x]);
        }
        for(int y = m; y >= q[i].l; --y){
            ans[y] = num;
            if(father(s[y]) != father(t[y])){
                num--;
                f[father(s[y])] = father(t[y]);
            }
        }
        for(int x = j + 1; x <= i; ++x)
            res[q[x].no] = ans[q[x].r];
    }
    rep(i, k) printf("%d\n", res[i]);
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/07/18 00:05:59
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
#define MAXN 300010
using namespace std;

int n, q, x, y, t, x_, y_, a[MAXN], pos[MAXN], num[MAXN], s[MAXN];

void add(int k, int p){
    for(; k <= n; k += k & -k)
        num[k] += p;
}

int sum(int k){
    int res = 0;
    for(; k; k -= k & -k)
        res += num[k];
    return res;
}

void init(){
    int cnt = 1, p = 0;
    rep(i, n){
        if(pos[i] < p)
            ++cnt;
        p = pos[i];
        s[i] = cnt;
    }
    rep(i, n)
        add(i, s[i] - s[i - 1]);
    pos[0] = n + 1;
}

int main(){
    scanf("%d", &n);
    rep(i, n)
        scanf("%d", &a[i]), pos[a[i]] = i;
    init();
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d", &t, &x, &y);
        if(t == 1){
            int ans = sum(y) - sum(x - 1);
            if(pos[x - 1] < pos[x])
                ++ans;
            printf("%d\n", ans);
        }
        else if(x != y){
            x_ = x;
            y_ = y;
            x = a[x];
            y = a[y];
            swap(a[x_], a[y_]);
            if(x > y)
                swap(x, y);
            if(x + 1 < y){
                bool t1 = pos[x - 1] < pos[x];
                bool t2 = pos[x] < pos[x + 1];
                bool t3 = pos[x - 1] < pos[y];
                bool t4 = pos[y] < pos[x + 1];
                if(t1 != t3){
                    if(t1)
                        add(x, 1);
                    else
                        add(x, -1);
                }
                if(t2 != t4){
                    if(t2)
                        add(x + 1, 1);
                    else
                        add(x + 1, -1);
                }
                t1 = pos[y - 1] < pos[y];
                t2 = pos[y] < pos[y + 1];
                t3 = pos[y - 1] < pos[x];
                t4 = pos[x] < pos[y + 1];
                if(t1 != t3){
                    if(t1)
                        add(y, 1);
                    else
                        add(y, -1);
                }
                if(t2 != t4){
                    if(t2)
                        add(y + 1, 1);
                    else
                        add(y + 1, -1);
                }
                swap(pos[x], pos[y]);
            }
            else{
                bool t1 = pos[x - 1] < pos[x];
                bool t2;
                bool t3 = pos[x - 1] < pos[y];
                bool t4;
                if(t1 != t3){
                    if(t1)
                        add(x, 1);
                    else
                        add(x, -1);
                }
                t1 = pos[x] < pos[y];
                t2 = pos[y] < pos[y + 1];
                t4 = pos[x] < pos[y + 1];
                if(t1)
                    add(y, 1);
                else
                    add(y, -1);
                if(t2 != t4){
                    if(t2)
                        add(y + 1, 1);
                    else
                        add(y + 1, -1);
                }
                swap(pos[x], pos[y]);
            }
        }
    }
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/07/17 23:32:17
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

map<int, int> p;
int n, a[MAXN], t, l, r;
long long s[MAXN], ans = -10000000000000000ll;

int main(){
    cin >> n;
    rep(i, n){
        scanf("%d", &a[i]);
        s[i] = s[i - 1];
        if(a[i] > 0)
            s[i] += (long long)a[i];
        if(!p[a[i]])
            p[a[i]] = i;
        else{
            t = p[a[i]];
            if(s[i - 1] - s[t] + (long long)a[i] * 2 > ans)
                ans = s[i - 1] - s[t] + a[i] * 2, l = t, r = i;
        }
    }
    int cnt = l - 1 + n - r;
    for(int i = l + 1; i < r; ++i)
        if(a[i] < 0)
            ++cnt;
    cout << ans << " " << cnt << endl;
    for(int i = 1; i < l; ++i){
        --cnt;
        printf("%d%c", i, (cnt ? ' ' : '\n'));
    }
    for(int i = l + 1; i < r; ++i)
        if(a[i] < 0){
            --cnt;
            printf("%d%c", i, (cnt ? ' ' : '\n'));
        }
    for(int i = r + 1; i <= n; ++i){
        --cnt;
        printf("%d%c", i, (cnt ? ' ' : '\n'));
    }
    return 0;
}

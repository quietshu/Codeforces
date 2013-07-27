/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/06/07 23:46:53
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

int b, d, la, lb, g[200];
char a[200], c[200], p[26];
pair<int, int> f[200];

int main(){
    scanf("%d%d%s%s", &b, &d, a, c);
    la = strlen(a);
    lb = strlen(c);
    rep(i, la)
        p[a[i - 1] - 'a'] = 1;
    rep(i, lb)
        if(!p[c[i - 1] - 'a']){
            puts("0");
            return 0;
        }

    rep(i, la){
        int top = i - 1;
        while(!f[i - 1].first){
            ++g[i - 1];
            rep(j, lb){
                while(a[top] != c[j - 1]){
                    top = (top + 1) % la;
                    if(!top)
                        ++f[i - 1].first;
                }
                top = (top + 1) % la;
                if(!top)
                    ++f[i - 1].first;
            }
            f[i - 1].second = top;
        }
    }

    int st = f[0].second, q = f[0].first + 1, num = 0;
    while(q <= b || (q == b + 1 && !st)){
        num += g[st];
        q += f[st].first;
        st = f[st].second;
    }
    printf("%d\n", num / d);
    return 0;
}

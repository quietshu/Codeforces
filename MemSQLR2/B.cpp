/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/08/04 01:15:45
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

int n, tmp, f[110], g[110], next[50010], top[100], st[50010];
char s[50010], t[50010];

int main(){
    scanf("%s", s);
    n = strlen(s);
    memset(top, -1, sizeof top);
    rep(i, n){
        t[i - 1] = s[n - i];
        next[i - 1] = top[t[i - 1] - 'a'];
        top[t[i - 1] - 'a'] = i - 1;
    }
    rep(i, 50)
        f[i] = n + 1;
    f[0] = g[0] = -1;
    rep(i, n){
        while(i - 1 + top[s[i - 1] - 'a'] >= n - 1)
            top[s[i - 1] - 'a'] = next[top[s[i - 1] - 'a']];
        rep(j, 50)
            if(f[j - 1] < top[s[i - 1] - 'a']){
                tmp = top[s[i - 1] - 'a'];
                while(next[tmp] > f[j - 1])
                    tmp = next[tmp];
                if(tmp < f[j])
                    f[j] = tmp, g[j] = i - 1;
            }
    }
    for(int i = 50; i >= 0; --i)
        if(f[i] < n + 1){
            if(i == 50){
                rep(j, 50)
                    printf("%c", t[f[j]]);
                rep(j, 50)
                    printf("%c", t[f[51 - j]]);
                puts("");
                return 0;
            }
            else{
                if(f[i] + g[i] == n - 2){
                    rep(j, i)
                        printf("%c", t[f[j]]);
                    rep(j, i)
                        printf("%c", t[f[i + 1 - j]]);
                    puts("");
                    return 0;
                }
                else{
                    rep(j, i)
                        printf("%c", t[f[j]]);
                    printf("%c", t[f[i] + 1]);
                    rep(j, i)
                        printf("%c", t[f[i + 1 - j]]);
                    puts("");
                    return 0;
                }
            }
        }
    return 0;
}

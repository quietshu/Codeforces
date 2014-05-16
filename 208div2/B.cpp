/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/10/25 23:47:29
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

int n, tot, st[100010];
char s[100010], g[100010], c[100010];

int main(){
    scanf("%d\n", &n);
    rep(i, n){
        scanf("%s", s + tot);
        st[i] = tot;
        tot = strlen(s);
    }
    scanf("%s", g);
    int l = strlen(g), top, tmp = 0;
    for(int i = 0; i < l; ++i){
        if(g[i] >= 'a' && g[i] <= 'z')
            g[tmp++] = g[i];
        if(g[i] == '3' || g[i] == '<')
            g[tmp++] = g[i];
    }
    l = tmp; tmp = 0;
    for(int i = 0; i < l; ++i){
        if(g[i] >= 'a' && g[i] <= 'z'){
            g[tmp++] = g[i];
            continue;
        }
        if(g[i] != '3' && g[i] != '<')
            continue;
        if(g[i] == '<' && (i == l - 1 || g[i + 1] != '3'))
            continue;
        if(g[i] == '3' && (!i || g[i - 1] != '<'))
            continue;
        g[tmp++] = g[i];
    }
    l = tmp;
    st[n + 1] = tot;
    tot = 1;
    for(int i = 0, j; i < l; i = j){
        j = i;
        if(j < l - 1 && g[j] == '<' && g[j + 1] == '3'){
            j += 2;
            continue;
        }
        top = 0;
        while(j < l && (j == l - 1 || (g[j] != '<' || g[j + 1] != '3')))
            c[top++] = g[j++];
        if(tot > n || top != st[tot + 1] - st[tot]){
            puts("no");
            return 0;
        }
        else{
            for(int k = 0; k < top; ++k)
                if(c[k] != s[st[tot] + k]){
                    puts("no");
                    return 0;
                }
        }
        ++tot;
    }
    puts("yes");
    return 0;
}

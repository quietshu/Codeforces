/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/07/20 21:29:49
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

int n;
bool g[200][200], f[200][200], t[200], p[200];
char c;

int main(){
    cin >> n;
    rep(i, n)
        rep(j, n){
            c = getchar();
            while(c != '.' && c != 'E')
                c = getchar();
            g[i][j] = (c == '.');
            if(g[i][j])
                rep(k, n)
                    f[i][k] = f[k][j] = 1;
        }
    rep(i, n)
        rep(j, n){
            if(!f[i][j]){
                cout << -1 << endl;
                return 0;
            }
            t[i] += g[i][j];
            p[j] += g[i][j];
        }
    bool ck = 1;
    rep(i, n)
        if(!t[i]){
            ck = 0;
            break;
        }
    if(ck){
        rep(i, n){
            rep(j, n)
                if(g[i][j]){
                    printf("%d %d\n", i, j);
                    break;
                }
        }
        return 0;
    }
    ck = 1;
    rep(i, n)
        if(!p[i]){
            ck = 0;
            break;
        }
    if(ck){
        rep(j, n){
            rep(i, n)
                if(g[i][j]){
                    printf("%d %d\n", i, j);
                    break;
                }
        }
        return 0;
    }
    puts("-1");
    return 0;
}

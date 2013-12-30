/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/12/30 23:36:16
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

int n, a[400];

int main(){
    cin >> n;
    rep(i, n) cin >> a[i];
    bool t = 1;
    while(t){
        t = 0;
        printf("R");
        for(int i = 2; i <= n; ++i){
            if(a[i])
                t = 1, printf("P"), a[i]--;
            if(i != n)
                printf("R");
        }
        rep(i, n - 1){
            printf("L");
            if(a[n - i])
                t = 1, printf("P"), a[n - i]--;
        }
    }
    puts("");
    return 0;
}

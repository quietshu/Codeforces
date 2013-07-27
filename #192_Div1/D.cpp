/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/07/20 22:39:38
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

int n, x;

int main(){
    cin >> n >> x;
    if(n == 5){
        puts(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1");
        return 0;
    }
    if(n == 3){
        puts(">vv\n^<.\n^.<\n1 3");
        return 0;
    }
    rep(i, n / 2){
        printf("v");
        rep(i, n / 3 - 1)
            printf(".<");
        printf(".");
        rep(i, n / 3)
            printf("<");
        puts(".");
        rep(i, n / 3)
            printf(">");
        rep(i, n / 3 - 1)
            printf(".>");
        printf(".^");
        puts(".");
    }
    puts("1 1");
    return 0;
}

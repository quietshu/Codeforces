/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/05/30 23:37:59
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

char s[100010];
int num[100010];

int main(){
    scanf("%s", s);
    int len = strlen(s);
    for(int i = 1; i < len; ++i)
        num[i] = num[i - 1] + (s[i] == s[i - 1]);
    int q; cin >> q;
    int l, r;
    while(q--){
        scanf("%d%d", &l, &r);
        printf("%d\n", num[r - 1] - num[l - 1]);
    }
    return 0;
}

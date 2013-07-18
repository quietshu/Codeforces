/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/06/07 23:33:38
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
#define MAXN 200010
using namespace std;

int n, k, r[MAXN];
long long d;

int main(){
    scanf("%d%d", &n, &k);
    rep(i, n)
        scanf("%d", &r[i]);
    int num = 1, tot = n;
    rep(i, n){
        if(d - (long long)(tot - num) * (num - 1) * r[i] < k){
            printf("%d\n", i);
            tot--;
        }
        else{
            d += (long long)r[i] * (num - 1);
            num++;
        }
    }
    return 0;
}

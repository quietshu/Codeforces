/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/05/30 23:44:54
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

int n, a[2000010];
long long ans;

int main(){
    cin >> n;
    rep(i, n)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for(int t = 1; t <= n; t <<= 2)
        rep(j, t)
            ans += (long long)a[n - j + 1];
    cout << ans << endl;
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/04/15 23:39:49
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
long long ans, tot;

int main(){
    cin >> n;
    int l = 0, t, c;
    rep(i, n){
        scanf("%d%d", &t, &c);
        tot = max(0ll, tot - t + l);
        tot += c;
        ans = max(ans, tot);
        l = t;
    }
    cout << l + tot << " " << ans << endl;
    return 0;
}

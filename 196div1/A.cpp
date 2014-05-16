/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/08/16 23:59:07
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
#define mod 1000000009
using namespace std;

int n, m, k, ans;

int power(int a, int b){
    if(!b)
        return 1;
    int tmp = power(a, b / 2);
    tmp = (long long)tmp * tmp % mod;
    if(b & 1)
        tmp = (long long)tmp * a % mod;
    return tmp;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);
    ans = 0;
    int cnt = min(m / (k - 1), n - m);
    int t = (m - cnt * (k - 1)) / k;
    ans = (ans + (long long)(power(2, t + 1) - 2) * k % mod) % mod;
    ans = (ans + (k - 1) * cnt) % mod;
    ans = (ans + m - t * k - (k - 1) * cnt) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
    return 0;
}

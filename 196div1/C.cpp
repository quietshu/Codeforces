/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/08/17 01:11:34
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

int n, m, bel[10], ans = 1000;
long long a[10], b[10], c[10], d[10];

int cntPrime(long long x){
    if(x == 1)
        return 0;
    int cnt = 0;
    for(long long i = 2; i * i <= x; ++i)
        if(x % i == 0){
            while(x % i == 0)
                x /= i, ++cnt;
        }
    if(x != 1)
        ++cnt;
    if(cnt == 1)
        --cnt;
    return cnt;
}

void calc(){
    int cnt = (m != 1);
    for(int i = 1; i <= m; ++i)
        cnt += cntPrime(c[i]);
    ans = min(ans, cnt + n);
}

void dfs(int v){
    if(v > n){
        calc();
        return;
    }
    for(int i = 1; i < v; ++i)
        if(a[i] % a[v] == 0){
            a[i] /= a[v];
            dfs(v + 1);
            a[i] *= a[v];
        }
    c[++m] = a[v];
    dfs(v + 1);
    --m;
}

long long tmp[10];

int main(){
    cin >> n;
    rep(i, n)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for(int i = 1, j = n; i <= j; ++i, --j)
        swap(a[i], a[j]);
    dfs(1);
    cout << ans << endl;
    return 0;
}

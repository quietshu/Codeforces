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

int n, m, bel[10], ans = 1000, pn;
long long a[10], b[10], c[10], d[10], prime[1000];

int cntPrime(long long x){
    if(x == 1)
        return 0;
    int cnt = 0;
    for(int i = 1; i <= pn && prime[i] * prime[i] <= x; ++i)
        if(x % prime[i] == 0){
            while(x % prime[i] == 0){
                x /= prime[i];
                ++cnt;
            }
        }
    if(x != 1)
        ++cnt;
    if(cnt == 1)
        return 0;
    return cnt;
}

void calc(){
    int cnt = 1, top = 0;
    for(int i = 1; i <= m; ++i){
        top = 0;
        for(int j = 1; j <= n; ++j)
            if(bel[j] == i)
                c[++top] = a[j], d[top] = a[j];
        sort(c + 1, c + 1 + top);
        for(int j = top; j; --j)
            for(int k = top; k > j; --k)
                if(d[j] % c[k] == 0){
                    d[j] /= c[k];
                    break;
                }
        cnt += top;
        for(int j = 1; j <= top; ++j)
            cnt += cntPrime(d[j]);
    }
    ans = min(ans, cnt);
}

void dfs(int v){
    if(v > n){
        calc();
        return;
    }
    for(int i = 1; i <= m; ++i){
        if(b[i] > a[v] && b[i] % a[v] == 0){
            bel[v] = i;
            dfs(v + 1);
        }
        else if(a[v] % b[i] == 0){
            bel[v] = i;
            long long tmp = b[i];
            b[i] = a[v];
            dfs(v + 1);
            b[i] = tmp;
        }
    }
    bel[v] = ++m;
    b[m] = a[v];
    dfs(v + 1);
    --m;
}

long long tmp[10];

void init(){
    rep(i, n) tmp[i] = a[i];
    for(long long i = 2; ; ++i){
        bool check = 0, pp = 0;
        rep(j, n)
            if(i * i <= tmp[j]){
                check = 1;
                while(tmp[j] % i == 0){
                    tmp[j] /= i;
                    if(!pp)
                        prime[++pn] = i, pp = 1;
                }
            }
        if(!check)
            break;
    }
    rep(i, n) if(tmp[i] != 1)
        prime[++pn] = tmp[i];
}

int main(){
    cin >> n;
    rep(i, n)
        cin >> a[i];
    init();
    dfs(1);
    cout << ans << endl;
    return 0;
}

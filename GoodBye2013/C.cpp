/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : C.cpp
*   Creation Time : 2013/12/30 23:45:06
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
#define MAXN 300010
using namespace std;

struct data{
    int no, sc;
    bool operator < (const data &d) const{
        return sc < d.sc;
    }
} d[MAXN];

int n;
long long b[MAXN];

int main(){
    cin >> n;
    rep(i, n)
        scanf("%d", &d[i].sc), d[i].no = i;
    sort(d + 1, d + 1 + n);
    long long s = -1;
    rep(i, n){
        if(s < d[i].sc)
            s = d[i].sc;
        b[d[i].no] = s;
        s++;
    }
    rep(i, n)
        printf("%I64%c", b[i], (i == n ? '\n' : ' ' ));
    return 0;
}

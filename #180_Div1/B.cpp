/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/04/19 23:55:42
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

int n, m, k, x;
multiset<int> s, p;

int main(){
    cin >> n >> m >> k;
    int res = 0;
    rep(i, n){
        scanf("%d", &x);
        s.insert(-x);
    }
    rep(i, m){
        scanf("%d", &x);
        p.insert(-x);
    }
    for(multiset<int>::iterator it = s.begin(); it != s.end(); ++it){
        if(p.empty()){
            puts("YES");
            return 0;
        }
        if(!p.empty() && *p.begin() <= *it){
            p.erase(p.begin());
            --n;
        }
    }
    puts(n != 0 ? "YES" : "NO");
    return 0;
}

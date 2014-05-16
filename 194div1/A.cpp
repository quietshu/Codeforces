/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/07/27 16:28:31
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

long long n, cnt = 1, m = 1, p = 1;

int main(){
    cin >> n;
    while(m <= n)
        m *= 3, p *= 3;
    p /= 3;
    while(p){
        if(m - p != n && m - p - p != n){
            cnt *= 3;
            if(m - p > n)
                m -= p, cnt--;
            if(m - p > n)
                m -= p, cnt--;
        }
        else
            break;
        p /= 3;
    }
    cout << cnt << endl;
    return 0;
}

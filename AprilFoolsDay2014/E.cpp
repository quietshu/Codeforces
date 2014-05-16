/*
*   Copyright (C) Ds ds303077135@gmail.com
*   File Name     : E.cpp
*   Creation Time : 2014/04/02 00:28:29
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
#define pi acos(-1)
using namespace std;

double getR(int a, int h){
    double x = a * 0.5;
    double y = h;
    double r = x * y / sqrt(x * x + y * y);
    return r;
}

int main(){
    double r;
    cin >> r;
    rep(i, 10)
        rep(j, 10)
            if(fabs(getR(i, j) - r) < 0.000001){
                printf("%d %d\n", i, j);
                return 0;
            }
    return 0;
}

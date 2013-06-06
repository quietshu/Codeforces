/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/05/30 23:31:35
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

int main(){
    cin >> n;
    if(n >= 0)
        cout << n << endl;
    else
        if(abs(n) % 10 > (abs(n) / 10) % 10)
            cout << n / 10 << endl;
        else
            cout << -(abs(n / 100) * 10 + abs(n) % 10) << endl;
    return 0;
}

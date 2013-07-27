/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/05/06 00:06:33
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

int n, a;

int main(){
    cin >> n;

    int ne = 0, sum = 0, ze = 0, m = 100000;

    rep(i, n + n - 1){
        scanf("%d", &a);
        ne += a < 0;
        ze += a == 0;
        a = abs(a);
        sum += a;
        m = min(m, a);
    }

    if(ne % 2 == 0 || ze || (ne - n) % 2 == 0)
        cout << sum << endl;
    else
        cout << sum - 2 * m << endl;
    return 0;
}

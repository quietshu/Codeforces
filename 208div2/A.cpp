/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/10/25 23:26:43
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

int x[1010];

int main(){
    int n, l = -1000000, r = 1000000;
    cin >> n;
    rep(i, n){
        scanf("%d", &x[i]);
        for(int j = 1; j + 1 < i - 1; ++j){
            if(x[i] > min(x[j], x[j + 1]) && x[i] < max(x[j], x[j + 1])
            && (x[i - 1] <min(x[j], x[j + 1]) || x[i - 1] > max(x[j], x[j + 1]))){
                puts("yes");
                return 0;
            }
            if(x[i - 1] > min(x[j], x[j + 1]) && x[i - 1] < max(x[j], x[j + 1])
            && (x[i] <min(x[j], x[j + 1]) || x[i] > max(x[j], x[j + 1]))){
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
    return 0;
}

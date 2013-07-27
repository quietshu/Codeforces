/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/04/19 23:33:28
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

char a[1010], b[1010];
int x, y, num;

bool solve(int pos){
    int l = 0, r = x - pos;
    bool t = (num & 1);
    while(l <= pos && r < y){
        if(t == (b[r] == '1')){
            ++r;
            if(t)
                t ^= 1;
        }
        else{
            t ^= (a[l] == '1');
            ++l;
        }
    }
    return r == y;
}

int main(){
    scanf("%s%s", a, b);
    x = strlen(a); y = strlen(b);
    rep(i, x) num += a[i - 1] == '1';
    for(int i = x; i >= 0 && i >= x - y; --i){
        bool check = 1;
        for(int j = i; j < x; ++j)
            check &= (a[j] == b[j - i]);
        if(check && solve(i)){
            puts("YES");
            return 0;
        }
    }
    for(int i = y; i; --i)
        b[i] = b[i - 1];
    b[0] = char('0' + ('1' - b[1]));
    ++y;
    for(int i = x; i >= 0 && i >= x - y; --i){
        bool check = 1;
        for(int j = i; j < x; ++j)
            check &= (a[j] == b[j - i]);
        if(check && solve(i)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}


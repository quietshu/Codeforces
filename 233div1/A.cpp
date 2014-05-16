/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2014/03/01 23:31:05
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

int x, o;
long long s;

int main(){
    cin >> o >> x;
    if(!o){
        s = x;
        s *= s;
        s *= -1;
        cout << s << endl;
        rep(i, x)
            printf("x");
        puts("");
    }
    else if(o >= x + 1){
        if(o == x)
            s = 0;
        else if(o < x)
            s = -1;
        else if(!x)
            s = o, s *= s;
        else
            s = (o - x + 1), s *= s, s--;
        cout << s << endl;
        while(x || o){
            if(x)
                printf("x"), --x;
            if(o)
                printf("o"), --o;
        }
        puts("");
    }
    else{
        long long tmp = x / (o + 1);
        int x_ = x, o_ = o;
        while(x > tmp){
            if(o)
                s++, o--;
            s -= tmp * tmp;
            x -= tmp;
        }
        s -= (long long)x * x;
        cout << s << endl;
        while(x_ > tmp){
            rep(i, tmp)
                printf("x");
            x_ -= tmp;
            if(o_)
                printf("o"), o_--;
        }
        rep(i, x_)
            printf("x");
        puts("");
    }
    return 0;
}

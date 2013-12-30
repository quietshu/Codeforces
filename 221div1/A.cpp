/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/12/24 22:00:58
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

char c;
int c1, c6, c8, c9, c0;

int main(){/*
    c = getchar();
    while(c >= '0' && c <= '9'){
        switch(c){
            case '0': c0++; break;
            case '1': c1++; break;
            case '6': c6++; break;
            case '8': c8++; break;
            case '9': c9++; break;
        }
        c = getchar();
    }*/
    for(int i = 0; i <= 10000; ++i){
        int t = i * 7;
        bool tmp = 1;
        while(t){
            if(t % 10 != 1 && t % 10 != 0 && t % 10 != 6 && t % 10 != 8 && t % 10 != 9){
                tmp = 0;
                break;
            }
            t /= 10;
        }
        if(tmp) printf("%d\n", i * 7);
    }
    return 0;
}

/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : A.cpp
*   Creation Time : 2013/04/22 23:43:17
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

int n, n1, n2, n0;
char s[2000010], t[2000010];

int main(){
    scanf("%d%s%s", &n, s, t);
    rep(i, n * 2){
        if(s[i - 1] == '1'){
            if(t[i - 1] == '1')
                n0++;
            else
                n1++;
        }
        else{
            if(t[i - 1] == '1')
                n2++;
        }
    }
    int t1 = 0, t2 = 0;
    bool p = 1;
    while(n0 + n1 + n2){
        if(n0){
            if(p) t1++;
            else t2++;
            n0--;
        }
        else if(n1){
            if(p) t1++;
            n1--;
        }
        else if(n2){
            if(!p) t2++;
            n2--;
        }
        p = !p;
    }
    puts(t1 == t2 ? "Draw" : (t1 > t2 ? "First" : "Second"));
    return 0;
}

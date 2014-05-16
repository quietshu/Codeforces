/*
*   Copyright (C) Ds ds303077135@gmail.com
*   File Name     : A.cpp
*   Creation Time : 2014/04/01 23:36:44
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

char a[100], b[100];
int cnt;

int main(){
    cnt = 0;
    scanf("%s%s", a, b);
    int l = strlen(a);
    for(int i = 0; i < l; i += 2){
        int A = (a[i] == '[' ? 0 : (a[i] == '(' ? 1 : 2));
        int B = (b[i] == '[' ? 0 : (b[i] == '(' ? 1 : 2));
        if(A == 0){
            if(B == 2)
                cnt -= 2;
            else if(B == 1)
                cnt += 2;
        }
        else if(A == 1){
            if(B == 0) 
                cnt -= 2;
            else if(B == 2)
                cnt += 2;
        }
        else if(A == 2){
            if(B == 0) 
                cnt += 2;
            else if(B == 1) 
                cnt -= 2;
        }
    }
    if(cnt > 0) puts("TEAM 1 WINS");
    else if(cnt < 0) puts("TEAM 2 WINS");
    else puts("TIE");
    return 0;
}

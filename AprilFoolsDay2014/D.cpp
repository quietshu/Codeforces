/*
*   Copyright (C) Ds ds303077135@gmail.com
*   File Name     : D.cpp
*   Creation Time : 2014/04/02 01:07:34
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
//          123456789ABCDEFG
char t[] = "1001010111001010";

int main(){
    int n; cin >> n;
    cout << t[n-1] << endl;
    return 0;
}

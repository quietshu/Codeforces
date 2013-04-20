/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : cf.cpp
*	Creation Time : 2013/02/13 20:57:46
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
#define mod 1000000007
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	f[1][1][m] = ((m * m + m) / 2 + 1) % mod;
	for(int i = 2; i <= n; ++i){
	}
	return 0;
}

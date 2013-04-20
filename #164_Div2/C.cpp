/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : C.cpp
*	Creation Time : 2013/01/28 22:32:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	printf("%d\n", min(n, m) + 1);
	rep(i, min(n, m) + 1)
		printf("%d %d\n", min(n, m) + 1 - i, i - 1);
	return 0;
}

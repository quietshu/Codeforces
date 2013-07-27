/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/01/16 22:29:36
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, k, a[100];

int main(){
	scanf("%d%d", &n, &k);
	rep(i, n)
		scanf("%d", &a[i]);
	if(k > n){
		printf("-1\n");
		return 0;
	}
	sort(a + 1, a + 1 + n);
	printf("%d 0\n", a[n - k + 1]);
	return 0;
}

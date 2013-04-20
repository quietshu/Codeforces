/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/01/08 18:34:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, k, a[100], tot, ans = 100;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	rep(i, n)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	tot = k;
	for(int i = 0; i <= n; ++i){
		if(tot >= m){
			printf("%d\n", i);
			return 0;
		}
		tot = tot - 1 + a[n - i];
	}
	printf("-1\n");
	return 0;
}


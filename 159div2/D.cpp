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
#define MAXN 100050
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a[MAXN];
long long s, sum;
bool t[MAXN];

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &a[i]);
		s += a[i];
	}
	for(int i = n; i; --i)
		if(sum + 2 * a[i] <= s)
			t[i] = 1, sum += 2 * a[i];
	rep(i, n)
		printf("%c", t[i] ? '-' : '+');
	puts("");
	return 0;
}

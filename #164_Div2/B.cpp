/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/01/28 22:32:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, tot;

int main(){
	scanf("%d", &n);
	rep(i, n)
		tot += i * (n - i);
	cout << tot + n << endl;
	return 0;
}

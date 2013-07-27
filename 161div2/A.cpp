/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/01/16 22:29:36
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int a, x, y;

int main(){
	rep(i, 5)
		rep(j, 5){
			scanf("%d", &a);
			if(a)
				x = i, y = j;
		}
	printf("%d\n", abs(3 - x) + abs(3 - y));
	return 0;
}

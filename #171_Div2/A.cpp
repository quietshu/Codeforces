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
#define abs(x) (x > 0 ? x : -x)
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int x, y;

int main(){
	scanf("%d%d", &x, &y);
	if(x >= 0 && x >= y && y > -x + 1)
		printf("%d\n", 4 * (x - 1) + 1);
	else if(x < 0 && -x > y && x <= y)
		printf("%d\n", -x * 4 - 1);
	else if(y > 0 && y > x && y >= -x)
		printf("%d\n", y * 4 - 2);
	else
		printf("%d\n", -y * 4);
	return 0;
}

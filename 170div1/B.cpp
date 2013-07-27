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
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const double pi = acos(-1);
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	if(m == 3 && n >= 5)
		puts("-1");
	else{
		double arc = 2 * pi / m, tot = 0;
		rep(i, m){
			printf("%d %d\n", int(10000000 * cos(tot)), int(10000000 * sin(tot)));
			if(i + m <= n)
				printf("%d %d\n", int(5000000 * cos(tot + 0.1)), int(5000000 * sin(tot + 0.1)));
			tot += arc;
		}
	}
	return 0;
}

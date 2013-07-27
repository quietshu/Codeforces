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

int n, m, a, b;

int main(){
	scanf("%d", &n);
	while(n--){
		m = 0;
		scanf("%d%d", &a, &b);
		while(a > 0 && b > 0){
			if(a > b)
				a -= b;
			else
				b -= a;
			m++;
		}
		printf("%d\n", m);
	}
}


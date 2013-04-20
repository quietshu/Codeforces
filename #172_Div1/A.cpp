/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : cf.cpp
*	Creation Time : 2013/03/10 23:24:14
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const double pi = acos(-1);
int w, h, a;
double arc, tmp, r, ans;

int main(){
	scanf("%d%d%d", &w, &h, &a);
	arc = a / 180.0 * pi;
	
	r = sqrt(w * w + h * h);
	tmp = 2 * atan(h / w);
	
	ans = w * h * 4;

	if(arc <= tmp)
		ans -= 
	return 0;
}

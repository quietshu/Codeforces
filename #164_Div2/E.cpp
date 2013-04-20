/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : E.cpp
*	Creation Time : 2013/01/28 22:32:10
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, a, b;
double sum1, sum2, ans;
pair<double, double> s[50010];

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &a, &b);
		s[i].first = 1 - b / 100.0;
		s[i].second = a * b / 100.0;
		sum2 += s[i].first;
	}
	rep(i, n){

	}
	printf("%.10lf\n", ans);
	return 0;
}

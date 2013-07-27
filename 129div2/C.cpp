/*
* Copyright (C) 2012 All rights reserved.
* File name:  A.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.11
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

long long l, r, Pow[20];

long long getAns(long long n){
	int d = 1;
	long long ret = 0, tmp = n;
	while(n > 9){
		n /= 10;
		d++;
	}
	if(d == 1) return n;
	for(int i = 1; i < n; ++i)
		ret += Pow[d - 2];
	if(tmp % 10 >= n)
		ret += (tmp % Pow[d - 1]) / 10 + 1;
	else
		ret += (tmp % Pow[d - 1]) / 10;
	for(int i = 1; i < d; ++i){
		if(i == 1) ret += 9;
		else ret += Pow[i - 2] * 9;
	}
	return ret;
}

void init(){
	Pow[0] = 1;
	for(int i = 1; i <= 19; ++i)
		Pow[i] = Pow[i - 1] * 10;
}

int main(){
	scanf("%I64d%I64d", &l, &r);
	init();
	printf("%I64d\n", getAns(r) - getAns(l - 1));
}


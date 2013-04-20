/*
* Copyright (C) 2012 All rights reserved.
* File name:  B.cpp
* Author:     Parabola_ds
* Creat time: 2012.06.03
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

int t;
long long n;

long long gcd(long long a, long long b){
	return !b ? a : gcd(b, a % b);
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%I64d", &n);
		long long a = n + 1, b = 4 * n, g;
		g = gcd(a, b);
		a /= g, b /= g;
		cout << b + 1 << endl;
	}
	return 0;
}


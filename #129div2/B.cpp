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

int n;
long long l, delta, sum, a;

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%I64d", &a);
		if(a + delta >= l)
			l = a + delta;
		else{
			sum += l - a - delta;
			delta = l - a - delta;
			l = a + delta;
		}
	}
	printf("%I64d\n", sum);
	return 0;
}

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
#define MAXN 150000
#define PI 3.1415926535898
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, x, y;
double ang[MAXN];

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d%d", &x, &y);
		if(x == 0 && y == 0){
		}
		else{
			m++;
			if(x == 0)
				ang[m] = y > 0 ? 90 : 270;
			else if(y == 0)
				ang[m] = x > 0 ? 0 : 180;
			else{
				ang[m] = atan2(y, x) * 180.0 / PI;
				if(ang[m] < 0)
					ang[m] += 360.0;
			}
		}
	}
	sort(ang + 1, ang + 1 + m);
	double ans = 0;
	ang[m + 1] = ang[1] + 360.0;
	for(int i = 1; i <= m; ++i)
		ans = max(ans, ang[i + 1] - ang[i]);
	printf("%.10lf\n", m > 1 ? 360.0 - ans : 0.0);
	return 0;
}

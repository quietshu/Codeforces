/*
* Copyright (C) 2012 All rights reserved.
* File name:  D.cpp
* Author:     Parabola_ds
* Creat time: 2012.07.04
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

const double inf = 1e20, eps = 1e-7;

struct Ball{
	double x, y, z, vx, vy, vz, t;
} ball, next[5];

double a, b, m, vx, vy, vz;

void calc(){
	next[0].t = - ball.y / ball.vy;
	next[0].x = ball.x + ball.vx * next[0].t;
	next[0].y = ball.y + ball.vy * next[0].t;
	next[0].z = ball.z + ball.vz * next[0].t;
	next[0].vx = ball.vx;
	next[0].vy = ball.vy;
	next[0].vz = ball.vz;
	next[1].t = next[2].t = next[3].t = next[4].t = inf;
	if(ball.vx < 0 && ball.x > 0){
		next[1].t = - ball.x / ball.vx;
		next[1].x = ball.x + ball.vx * next[1].t;
		next[1].y = ball.y + ball.vy * next[1].t;
		next[1].z = ball.z + ball.vz * next[1].t;
		next[1].vx = - ball.vx;
		next[1].vy = ball.vy;
		next[1].vz = ball.vz;
	}
	if(ball.vx > 0 && ball.x < a){
		next[2].t = (a - ball.x) / ball.vx;
		next[2].x = ball.x + ball.vx * next[2].t;
		next[2].y = ball.y + ball.vy * next[2].t;
		next[2].z = ball.z + ball.vz * next[2].t;
		next[2].vx = - ball.vx;
		next[2].vy = ball.vy;
		next[2].vz = ball.vz;
	}
	if(ball.vz < 0 && ball.z > 0){
		next[3].t = - ball.z / ball.vz;
		next[3].x = ball.x + ball.vx * next[3].t;
		next[3].y = ball.y + ball.vy * next[3].t;
		next[3].z = ball.z + ball.vz * next[3].t;
		next[3].vx = ball.vx;
		next[3].vy = ball.vy;
		next[3].vz = - ball.vz;
	}
	if(ball.vz > 0 && ball.z < b){
		next[4].t = (b - ball.z) / ball.vz;
		next[4].x = ball.x + ball.vx * next[4].t;
		next[4].y = ball.y + ball.vy * next[4].t;
		next[4].z = ball.z + ball.vz * next[4].t;
		next[4].vx = ball.vx;
		next[4].vy = ball.vy;
		next[4].vz = - ball.vz;
	}
	int d = 0;
	rep(i, 4)
		if(next[i].t < next[d].t)
			d = i;
	ball = next[d];
}

int main(){
	cin >> a >> b >> m >> vx >> vy >> vz;
	ball.x = a / 2.0;
	ball.y = m;
	ball.z = 0;
	ball.vx = vx;
	ball.vy = vy;
	ball.vz = vz;
	while(ball.y > eps)
		calc();
	printf("%.10lf %.10lf\n", ball.x, ball.z);
	return 0;
}

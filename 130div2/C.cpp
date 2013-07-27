/*
* Copyright (C) 2012 All rights reserved.
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
#define MAXN 200
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

const int inf = 1000000;

int n, m, a, b, dis[MAXN][MAXN], num[MAXN][MAXN];
double ans;

int main(){
    scanf("%d%d", &n, &m);
    rep(i, n)
        rep(j, n)
            dis[i][j] = inf;
    rep(i, m){
        scanf("%d%d", &a, &b);
        dis[a][b] = dis[b][a] = 1;
        num[a][b]++;
        num[b][a]++;
    }
    rep(k, n)
        rep(i, n)
            rep(j, n)
                if(dis[i][j] == dis[i][k] + dis[j][k])
                    num[i][j] += num[i][k] * num[k][j];
                else if(dis[i][j] > dis[i][k] + dis[j][k]){
                    dis[i][j] = dis[i][k] + dis[j][k];
                    num[i][j] = num[i][k] * num[k][j];
                }
    ans = num[1][n];
    for(int i = 2; i < n; ++i)
		if(dis[1][i] + dis[i][n] == dis[1][n])
	        ans = max(ans, 2.0 * num[1][i] * num[i][n]);
    printf("%.12lf\n", ans / num[1][n]);
}


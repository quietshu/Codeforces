/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : D.cpp
*   Creation Time : 2013/07/18 01:03:52
*   Environment   : OS X 10.8 & Vim 7.3
*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

vector<pair<pair<int, int>, int> > st[31][31][5];
int n, b, x, y, q, d, dx, dy;
bool ps[31][31][5];
long long t;
int dir[100][100];

bool move(int &x, int &y, int &d){
    if(dir[x][y])
        d = dir[x][y];
    if(d == 1)
        ++y;
    else if(d == 2)
        --y;
    else if(d == 3)
        --x;
    else if(d == 4)
        ++x;
    if(x < 0 || x > b || y < 0 || y > b)
        return 0;
    return 1;
}

void init(int i, int j, int k){
    int x, y, d;
    x = i;
    y = j;
    d = k;
    do{
        st[i][j][k].pb(mp(mp(x, y), d));
        if(!move(x, y, d)){
            ps[i][j][k] = 1;
            break;
        }
    } while(x != i || y != j || d != k);
}

void solve(){
    if(st[x][y][d].empty())
        init(x, y, d);
    if(st[x][y][d].size() <= t)
        if(ps[x][y][d])
            t = st[x][y][d].size() - 1;
        else 
            t %= (long long)st[x][y][d].size();
    printf("%d %d\n", st[x][y][d][t].first.first, st[x][y][d][t].first.second);
}

int main(){
    cin >> n >> b;
    rep(i, n){
        scanf("%d%d%d%d", &x, &y, &dx, &dy);
        if(dx > x)
            for(; x <= dx; ++x)
                dir[x][y] = 4;
        else if(dx < x)
            for(; x >= dx; --x)
                dir[x][y] = 3;
        else if(dy > y)
            for(; y <= dy; ++y)
                dir[x][y] = 1;
        else
            for(; y >= dy; --y)
                dir[x][y] = 2;
    }
    scanf("%d", &q);
    rep(i, q){
        scanf("%d%d", &x, &y);
        char c = getchar();
        while(c < 'A' || c > 'Z') c = getchar();
        d = (c == 'U' ? 1 : (c == 'D' ? 2 : (c == 'L' ? 3 : 4)));
        scanf("%lld", &t);
        solve();
    }
    return 0;
}

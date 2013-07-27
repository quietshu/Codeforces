/*
*   Copyright (C) Ds ds303077135@Gmail.com
*   File Name     : B.cpp
*   Creation Time : 2013/07/20 21:52:45
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
#define sign(x) (x < 0 ? -1 : (x > 0))
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

int r, c, x, y, X, Y, mp[1010][1010], dis[1010][1010];
bool vst[1010][1010];
char ch;
pair<int, int> que[1000010];

void spfa(){
    int p = 1;
    que[1] = make_pair(x, y);
    dis[x][y] = 0;
    vst[x][y] = 1;
    rep(i, p){
        if(mp[que[i].first][que[i].second] == -1)
            continue;
        if(que[i].first > 1 && dis[que[i].first][que[i].second] + 1 < dis[que[i].first - 1][que[i].second]){
            dis[que[i].first - 1][que[i].second] = dis[que[i].first][que[i].second] + 1;
            if(!vst[que[i].first - 1][que[i].second])
                que[++p] = make_pair(que[i].first - 1, que[i].second);
            vst[que[i].first - 1][que[i].second] = 1;
        }
        if(que[i].first < r && dis[que[i].first][que[i].second] + 1 < dis[que[i].first + 1][que[i].second]){
            dis[que[i].first + 1][que[i].second] = dis[que[i].first][que[i].second] + 1;
            if(!vst[que[i].first + 1][que[i].second])
                que[++p] = make_pair(que[i].first + 1, que[i].second);
            vst[que[i].first + 1][que[i].second] = 1;
        }
        if(que[i].second > 1 && dis[que[i].first][que[i].second] + 1 < dis[que[i].first][que[i].second - 1]){
            dis[que[i].first][que[i].second - 1] = dis[que[i].first][que[i].second] + 1;
            if(!vst[que[i].first][que[i].second - 1])
                que[++p] = make_pair(que[i].first, que[i].second - 1);
            vst[que[i].first][que[i].second - 1] = 1;
        }
        if(que[i].second < c && dis[que[i].first][que[i].second] + 1 < dis[que[i].first][que[i].second + 1]){
            dis[que[i].first][que[i].second + 1] = dis[que[i].first][que[i].second] + 1;
            if(!vst[que[i].first][que[i].second + 1])
                que[++p] = make_pair(que[i].first, que[i].second + 1);
            vst[que[i].first][que[i].second + 1] = 1;
        }
        vst[que[i].first][que[i].second] = 0;
    }
}

int main(){
    cin >> r >> c;
    rep(i, r)
        rep(j, c){
            ch = getchar();
            while(ch == '\n' || ch == '\r')
                ch = getchar();
            if(ch == 'S')
                X = i, Y = j;
            else if(ch == 'E')
                x = i, y = j;
            else if(ch == 'T')
                mp[i][j] = -1;
            else
                mp[i][j] = (ch - '0');
            dis[i][j] = 100000000;
        }
    spfa();
    int ans = 0;
    rep(i, r)
        rep(j, c)
            if(mp[i][j] > 0 && dis[i][j] <= dis[X][Y])
                ans += mp[i][j];
    cout << ans << endl;
    return 0;
}

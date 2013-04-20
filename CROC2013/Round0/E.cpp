/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : E.cpp
*	Creation Time : 2013/04/14 01:34:59
*	Environment   : OS X 10.8
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#define MAXN 100010
#define MAXL 300010
#define SEED 14741u
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

map<unsigned, unsigned long long> tailstr;
unsigned long long hash, power;
int n, v;
string s[MAXN], str;
vector<int> son[MAXN];
long long answer;

void calc(int v, unsigned long long h){
    int sn;
    unsigned long long tmp;
    rep(i, son[v].size()){
        sn = son[v][i - 1];
        tmp = h;
        rep(j, s[sn].size()){
            tmp = tmp * SEED + s[sn][j - 1] - 'Z';
            answer += tailstr[tmp - hash];
            tailstr[tmp * power]++;
        }
        calc(sn, tmp);
        tmp = h;
        rep(j, s[sn].size()){
            tmp = tmp * SEED + s[sn][j - 1] - 'Z';
            tailstr[tmp * power]--;
        }
    }
}

int main(){
    scanf("%d", &n);
    rep(i, n - 1){
       scanf("%d", &v);
       son[v].push_back(i + 1);
       cin >> s[i + 1];
    }
    cin >> str;
    power = 1;
    rep(i, str.size())
        hash = hash * SEED + str[i - 1] - 'Z', power *= SEED;
    tailstr[0] = 1;
    calc(1, 0u);
    cout << answer << endl;
    return 0;
}

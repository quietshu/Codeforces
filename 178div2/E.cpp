#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define sqr(x) ((x)*(x))
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n;
vector<pair<int, int> > E[5010];
long long sum, minS, s1, s2, S, _s1, _s2, ans;
int p, sn[5010], tot, p1, p2;

void dfs(int v, int f, long long s){
    if(s < minS){
        minS = s;
        p = v;
    }
    for(int i = 0; i < E[v].size(); ++i)
        if(E[v][i].first != f)
            dfs(E[v][i].first, v, s + (long long)E[v][i].second * (tot -
                        sn[E[v][i].first] * 2));
}

void init(int v, int f, long long s){
    sum += s;
    sn[v] = 1;
    for(int i = 0; i < E[v].size(); ++i)
        if(E[v][i].first != f){
            init(E[v][i].first, v, s + E[v][i].second);
            sn[v] += sn[E[v][i].first];
        }
}

void solve(int v, int t){
    sum = 0;
    init(v, E[v][t].first, 0);
    p = v; minS = sum; tot = sn[v];
    _s1 = sum;
    dfs(v, E[v][t].first, sum);
    p1 = p; s1 = minS;

    sum = 0;
    init(E[v][t].first, v, 0);
    p = E[v][t].first; minS = sum; tot = sn[E[v][t].first];
    _s2 = sum;
    dfs(E[v][t].first, v, sum);
    p2 = p; s2 = minS;

    ans = min(ans, S + (s2 - _s2) * sn[v] + (s1 - _s1) * (n - sn[v]));
}

void calc(int v, int f, long long s){
    S += s;
    for(int i = 0; i < E[v].size(); ++i)
        if(E[v][i].first != f)
            calc(E[v][i].first, v, s + E[v][i].second);
}

int main(){
    cin >> n;
    int a, b, c;
    rep(i, n - 1){
        scanf("%d%d%d", &a, &b, &c);
        E[a].push_back(make_pair(b, c));
        E[b].push_back(make_pair(a, c));
    }
    for(int i = 1; i <= n; ++i)
        calc(i, 0, 0);
    S /= 2;
    ans = S;
    for(int i = 1; i <= n; ++i)
        for(int j = 0; j < E[i].size(); ++j)
            if(i > E[i][j].first)
                solve(i, j);
    cout << ans << endl;
    return 0;
}

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <set>
#define MOD 1000000007
#define MAXN 500
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct edge{
	int s, t, next;
} e[MAXN * 5];

int etop, st[MAXN], in[MAXN];
int n, q, t, a[MAXN];
long long ans[100010], tmp[100010];
bool vst[MAXN];

void add(int s, int t){
	etop++;
	e[etop].t = t;
	e[etop].next = st[s];
	st[s] = etop;
}

long long solve(int v, int f, int p, int s){
	for(; p >= 0; --p)
		for(int i = st[v]; i; i = e[i].next) if(e[i].t != f){
			solve(e[i].t, v);
		}
	return 0;
}

int main(){
	scanf("%d%d%d", &n, &q, &t);
	rep(i, n)
		scanf("%d", &a[i]);
	rep(i, q){
		scanf("%d%d", &s, &t);
		vst[s] = 1;
		in[t]++;
		if(vst[t]){
			printf("0\n");
			return 0;
		}
		add(s, t);
		add(t, s);
	}
	rep(i, n) if(!in[i]){
		memset(tmp, 0, sizeof tmp);
		for(int k = 0; k <= t; ++k)
			tmp[k] = (tmp[k] + solve(i, 0, n, k)) % MOD;
	}
	return 0;
}


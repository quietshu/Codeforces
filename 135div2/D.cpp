#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 200010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct edge{
	int t, next;
	bool opp;
} e[MAXN * 2];

int n, ans[MAXN], sn[MAXN];
int st[MAXN], eTop;

void addEdge(int s, int t){
	eTop++;
	e[eTop].t = t;
	e[eTop].next = st[s];
	e[eTop].opp = 1;
	st[s] = eTop;
	eTop++;
	e[eTop].t = s;
	e[eTop].next = st[t];
	e[eTop].opp = 0;
	st[t] = eTop;
}

void dfs(int v, int f){
	sn[v] = 1;
	for(int i = st[v]; i; i = e[i].next)
		if(e[i].t != f){
			dfs(e[i].t, v);
			sn[v] += sn[e[i].t];
			if(e[i].opp)
				ans[v] += ans[e[i].t];
			else
				ans[v] += ans[e[i].t] + 1;
		}
}

void getAns(int v, int f){
	for(int i = st[v]; i; i = e[i].next)
		if(e[i].t != f){
			if(e[i].opp)
				ans[e[i].t] = ans[v] + 1;
			else
				ans[e[i].t] = ans[v] - 1;
			getAns(e[i].t, v);
		}
}

int main(){
	scanf("%d", &n);
	int a, b;
	for(int i = 1; i < n; ++i){
		scanf("%d%d", &a, &b);
		addEdge(a, b);
	}
	dfs(1, 0);
	getAns(1, 0);
	int tmp = ~0U >> 1;
	for(int i = 1; i <= n; ++i)
		tmp = min(tmp, ans[i]);
	printf("%d\n", tmp);
	for(int i = 1; i <= n; ++i)
		if(ans[i] == tmp)
			printf("%d ", i);
	return 0;
}
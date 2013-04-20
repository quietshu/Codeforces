#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct query{
	int l, r, id;
	bool operator < (const query &q) const{
		return r < q.r;
	}
} q[100010];

map<int, int> c, top, Top;
int n, m, a[MAXN], num[MAXN];
int pre[MAXN], next[MAXN], pos[MAXN];

void init(){
	for(int i = 1; i <= n; ++i){
		if(!c[a[i]])
			c[a[i]] = i, num[i] = 1, top[a[i]] = i;
		else
			num[c[a[i]]]++;
		next[Top[a[i]]] = i;
		pre[i] = Top[a[i]];
		Top[a[i]] = i;
		if(num[c[a[i]]] == a[i]){
			pos[i] = a[i] == 1 ? i : top[a[i]];
			top[a[i]] = next[top[a[i]]];
			num[c[a[i]]]--;
		}
	}
}

int ans[100010], s[100010];

void add(int l, int r, int v){
	for(int i = l; i <= n; i += i & -i)
		s[i] += v;
	for(int i = r + 1; i <= n; i += i & -i)
		s[i] -= v;
}

int ask(int l){
	int sum = 0;
	for(int i = l; i; i -= i & -i)
		sum += s[i];
	return sum;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	init();
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &q[i].l, &q[i].r);
		q[i].id = i;
	}
	sort(q + 1, q + 1 + m);
	int top = 1;
	for(int i = 1; i <= n; ++i){
		if(pre[i] && pos[pre[i]])
			add(pre[pos[pre[i]]] + 1, pos[pre[i]], -1);
		if(pos[i])
			add(pre[pos[i]] + 1, pos[i], 1);
		while(top <= m && q[top].r == i){
			ans[q[top].id] = ask(q[top].l);
			top++;
		}
	}
	for(int i = 1; i <= m; ++i)
		printf("%d\n", ans[i]);
	return 0;
}
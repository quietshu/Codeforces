/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : C.cpp
*	Creation Time : 2013/01/16 22:29:36
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define MAXN 100000
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

struct ring{
	int a, b, c;
	ring(){}
	ring(int A, int B, int C): a(A), b(B), c(C){}
	void init(){
		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
		if(a > b) swap(a, b);
	}
	bool operator < (const ring &r) const{
		return a < r.a || (a == r.a && (b < r.b || (b == r.b && c < r.c)));
	}
} r[MAXN * 3 + 10];

int n, rn, a[MAXN * 2 + 10], b[MAXN * 2 + 10];
int t[MAXN + 10][5], ans[MAXN + 10];
vector<pair<int, int> > xy[MAXN + 10];
bool u[MAXN + 10];

void solve(int a, int b, int c){
	bool succ = 0;
	for(vector<pair<int, int> >::iterator it = xy[b].begin(); it != xy[b].end(); ++it)
		if(it->first == c){
			succ = 1;
			break;
		}
	if(!succ) solve(b, c, a);
	else{
		for(vector<pair<int, int> >::iterator it = xy[b].begin(); it != xy[b].end(); ++it)
			 if(it->first == c){
				int tmp;
				if(r[it->second].a != c && r[it->second].a != b)
					tmp = r[it->second].a;
				else if(r[it->second].b != c && r[it->second].b != b)
					tmp = r[it->second].b;
				else
					tmp = r[it->second].c;
				bool ok = 0;
				for(vector<pair<int, int> >::iterator itt = xy[c].begin(); itt != xy[c].end(); ++itt)
					if(it->second != itt->second && itt->first == tmp){
						ok = 1;
						break;
					}
				if(!ok)
					swap(b, c);
				break;
			 }
		rep(i, n){
			ans[i] = a;
			for(vector<pair<int, int> >::iterator it = xy[b].begin(); it != xy[b].end(); ++it)
				if(it->first == c && !u[it->second]){
					u[it->second] = 1;
					a = b;
					b = c;
					if(r[it->second].a != a && r[it->second].a != b)
						c = r[it->second].a;
					else if(r[it->second].b != a && r[it->second].b != b)
						c = r[it->second].b;
					else
						c = r[it->second].c;
					break;
				}
		}
	}
}

int next[10];
bool vst[10], succ = 0;

void check(){
	int s = 1;
	bool suc, succc = 1;
	rep(i, n){
		suc = 0;
		rep(j, 4)
			if(t[s][j] == next[s]){
				suc = 1;
				break;
			}
		if(!suc){
			succc = 0;
			break;
		}
		s = next[s];
	}
	rep(i, n){
		suc = 0;
		rep(j, 4)
			if(t[s][j] == next[next[s]]){
				suc = 1;
				break;
			}
		if(!suc){
			succc = 0;
			break;
		}
		s = next[s];
	}
	if(succc)
		succ = 1;
}

void dfs(int p, int pre){
	if(succ)
		return;
	if(p > n){
		next[pre] = next[0];
		check();
		return;
	}
	for(int i = 1; i <= n; ++i)
		if(!vst[i] && !succ){
			vst[i] = 1;
			next[pre] = i;
			dfs(p + 1, i);
			vst[i] = 0;
		}
}

void buf(){
	dfs(1, 0);
	if(!succ)
		cout << "-1" << endl;
	else{
		int s = 1;
		rep(i, n - 1){
			cout << s << " ";
			s = next[s];
		}
		cout << s << endl;
	}
}

bool ck[MAXN + 10];

int main(){
	scanf("%d", &n);
	rep(i, 2 * n){
		scanf("%d%d", &a[i], &b[i]);
		t[a[i]][0]++;
		if(t[a[i]][0] <= 4)
			t[a[i]][t[a[i]][0]] = b[i];
		t[b[i]][0]++;
		if(t[b[i]][0] <= 4)
			t[b[i]][t[b[i]][0]] = a[i];
	}
	if(n <= 6){
		buf();
		return 0;
	}
	rep(i, n)
		if(t[i][0] != 4){
			cout << "-1" << endl;
			return 0;
		}
	rep(i, n)
		for(int j = 1; j <= 4; ++j)
			for(int k = j + 1; k <= 4; ++k)
				for(int p = 1; p <= 4; ++p)
					if(t[t[i][j]][p] == t[i][k])
						r[++rn] = ring(i, t[i][j], t[i][k]), r[rn].init();
	sort(r + 1, r + 1 + 3 * n);
	int top = 0;
	rep(i, 3 * n)
		if(r[i] < r[top] || r[top] < r[i]){
			++top;
			r[top].a = r[i].a;
			r[top].b = r[i].b;
			r[top].c = r[i].c;
		}
	if(top != n){
		cout << "-1" << endl;
		return 0;
	}
	for(int i = 2; i <= n; ++i){
		xy[r[i].a].push_back(make_pair(r[i].b, i));
		xy[r[i].a].push_back(make_pair(r[i].c, i));
		xy[r[i].c].push_back(make_pair(r[i].b, i));
		xy[r[i].c].push_back(make_pair(r[i].a, i));
		xy[r[i].b].push_back(make_pair(r[i].a, i));
		xy[r[i].b].push_back(make_pair(r[i].c, i));
	}
	solve(r[1].a, r[1].b, r[1].c);
	for(int i = 1; i <= n; ++i){
		if(ck[ans[i]]){
			cout << "-1" << endl;
			return 0;
		}
		ck[ans[i]] = 1;
	}
	rep(i, n - 1)
		printf("%d ", ans[i]);
	cout << ans[n] << endl;
	return 0;
}


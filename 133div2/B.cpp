#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int n, m, tot, oddRing, oddString;
vector<int> e[200];
bool vst[200];

int dfs(int v, int f){
	int l = 1, tot = 0, num = 0;
	vst[v] = 1;
	for(vector<int>::iterator it = e[v].begin(); it != e[v].end(); ++it)
	{
		tot++;
		if(!vst[*it] && *it != f)
			l += dfs(*it, v), num++;
	}
	if(!f){
		if(tot == 0)
			oddString++;
		else if(tot == 1 && l % 2 == 1)
			oddString++;
		else if(tot == 2 && num == 2 && l % 2 == 1)
			oddString++;
		else if(tot == 2 && num == 1 && l % 2 == 1)
			oddRing++;
	}
	return l;
}

int main(){
	scanf("%d%d", &n, &m);
	int a, b;
	rep(i, m){
		scanf("%d%d", &a, &b);
		e[a].push_back(b);
		e[b].push_back(a);
	}
	rep(i, n)
		if(!vst[i])
			dfs(i, 0);
	int ans = 0;
	ans += oddRing;
	if(oddString % 2 == 1)
		ans++;
	cout << ans << endl;
	return 0;
}
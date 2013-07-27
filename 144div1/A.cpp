#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int k, tot, n;
bool g[101][101];

int main(){
	scanf("%d", &k);
	int i = 2;
	while(tot < k){
		i++;
		if(tot + (i - 1) * (i - 2) / 2 > k)
			break;
		else
			tot += (i - 1) * (i - 2) / 2;
	}
	if(tot == k){
		printf("%d\n", i);
		rep(x, i){
			rep(y, i)
				printf("%c", x == y ? '0' : '1');
			puts("");
		}
		return 0;
	}
	int n = i - 1, p;
	rep(x, i - 1)
		rep(y, i - 1)
			g[x][y] = x != y;
	while(tot < k){
		n++;
		for(p = 2; tot + p * (p - 1) / 2 <= k; ++p);
		p--;
		tot += p * (p - 1) / 2;
		rep(x, p)
			g[x][n] = g[n][x] = 1;
	}
	printf("%d\n", n);
	rep(x, n){
		rep(y, n)
			printf("%c", g[x][y] ? '1' : '0');
		puts("");
	}
	return 0;
}
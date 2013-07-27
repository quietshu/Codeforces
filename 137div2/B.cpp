#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define LIM 1010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, k, num[LIM][LIM];
int row[LIM], col[LIM];

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &num[i][j]);
	for(int i = 1; i <= n; ++i)
		row[i] = i;
	for(int i = 1; i <= m; ++i)
		col[i] = i;
	int x, y;
	while(k--){
		char cmd = getchar();
		while(cmd != 'g' && cmd != 'r' && cmd != 'c')
			cmd = getchar();
		scanf("%d%d", &x, &y);
		if(cmd == 'g')
			printf("%d\n", num[row[x]][col[y]]);
		else if(cmd == 'r')
			swap(row[x], row[y]);
		else
			swap(col[x], col[y]);
	}
	return 0;
}
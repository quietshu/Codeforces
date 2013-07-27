#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, num[101][10001], ans = 1000000000;
int top[101], next[101][10001], tail[101];
char c;

int main(){
	scanf("%d%d", &n, &m);
	rep(i, n){
		top[i] = 0;
		rep(j, m){
			c = getchar();
			while(c != '1' && c != '0') c = getchar();
			num[i][j] = c == '1';
			if(num[i][j] && !top[i]) top[i] = j;
			if(num[i][j]) tail[i] = j;
		}
		if(!top[i]){
			puts("-1");
			return 0;
		}
		top[i] += m;
		for(int j = m; j; --j){
			next[i][j] = top[i];
			if(num[i][j])
				top[i] = j;
		}
	}
	rep(i, n)
		top[i] = tail[i] - m;
	int tmp;
	rep(i, m){
		tmp = 0;
		rep(j, n){
			if(num[j][i])
				top[j] = i;
			else
				tmp += min(i - top[j], next[j][i] - i);
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}
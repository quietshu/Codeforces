//That's so easy but I am so fool..
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define mod 1000000007
using namespace std;
int n, m;
bool t[101][30];
char c;
int main(){
	scanf("%d%d", &n, &m);
	memset(t, 0, sizeof(t));
	rep(i, n)
		rep(j, m){
			c = getchar();
			while(c < 'A' || c > 'Z')
				c = getchar();
			t[j][c - 'A'] = true;
		}
	long long tot = 1;
	rep(i, m){
		int T = 0;
		rep(j, 27)
			T += t[i][j - 1];
		tot = tot * T % mod;
	}
	printf("%d\n", tot);
	return 0;
}


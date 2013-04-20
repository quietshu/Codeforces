#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
int n, m, tot(0), M[101], Max[101], s[101][101];
int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	cin >> n >> m;
	char c = getchar();
	memset(Max, 0, sizeof(Max));
	memset(M, 0, sizeof(M));
	rep(i, n){
		while(c < '0' || c > '9')
			c = getchar();
		rep(j, m){
			s[i][j] = c - '0';
			if(c - '0' > Max[j])
				Max[j] = c - '0';
			c = getchar();
		}
	}
	rep(i, n)
		rep(j, m)
			if(s[i][j] == Max[j]){
				tot++;
				break;
			}
	printf("%d\n", tot);
	return 0;
}


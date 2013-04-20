#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 1000050
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int n, m, s[MAXN], t[MAXN];
long long tot = 0;
char c[MAXN];

int main(){
	scanf("%d", &n);
	scanf("%s", c);
	m = strlen(c);
	rep(i, m)
		s[i] = c[i - 1] - '0' + s[i - 1];
	t[0] = 1;
	rep(i, m){
		if(s[i] >= n)
			tot += t[s[i] - n];
		t[s[i]]++;
	}
	cout << tot << endl;
	return 0;
}

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define M 10000 + 10
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int n, m, ma = -M, mi = M, tot = 0;

int main(){
	scanf("%d%d", &n, &ma);
	mi = ma;
	rep(i, n - 1){
		scanf("%d", &m);
		if(m > ma){
			ma = m;
			tot++;
		} else
		if(m < mi){
			mi = m;
			tot++;
		}
	}
	cout << tot << endl;
	return 0;
}

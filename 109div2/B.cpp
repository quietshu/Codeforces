#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXN 1000 + 10
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << " = " << x << endl;

using namespace std;

struct card{
	int a, b;
	bool operator < (const card &_c) const{
		return b > _c.b || (b == _c.b && a > _c.a);
	}
} c[MAXN];

int n, ct = 1, p = 0, s = 1;

int main(){
	cin >> n;
	rep(i, n)
		scanf("%d%d", &c[i].a, &c[i].b);
	sort(c + 1, c + 1 + n);
	while(ct && s <= n){
		ct += c[s].b - 1;
		p += c[s].a;
		s++;
	}
	printf("%d\n", p);
	return 0;
}

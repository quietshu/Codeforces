#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int a, b, c;

int main(){
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", b * c + (b + c - 1) * (a - 1));
	return 0;
}
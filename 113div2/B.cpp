#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

int n, m, t;
long long x[2][100000], y[2][100000];
long long s;
bool q;

bool inp(int v){
	s = x[1][v] * y[0][n - 1] + y[1][v] * x[0][0] + x[0][n - 1] * y[0][0] - y[0][n - 1] * x[0][0] - y[0][0] * x[1][v] - y[1][v] * x[0][n - 1];
	q = (s > 0);
	if(s == 0)
		return 0;
	rep(i, n - 2){
		s = x[1][v] * y[0][i] + y[1][v] * x[0][(i + 1) % n] + x[0][i] * y[0][(i + 1) % n] - y[0][i] * x[0][(i + 1) % n] - y[0][(i + 1) % n] * x[1][v] - y[1][v] * x[0][i];
		if(q){
			if(s <= 0)
				return 0;
		} else
		if(s >= 0)
			return 0;
	}
	return 1;
}

bool init(){
	rep(i, m){
		if(!inp(i))
			return 0;
		if(double(clock() - t) / CLOCKS_PER_SEC >= 1.9)
			return clock() & 1;
	}
	return 1;
}

inline void read(long long &n){
	char c = getchar();
	bool ant = 0;
	n = 0;
	while(c < '0' || c > '9'){
		if(c == '-')
			ant = 1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		n = n * 10 + c - '0';
		c = getchar();
	}
	if(ant)
		n = -n;
}

int main(){
	t = clock();
	scanf("%d", &n);
	rep(i, n){
		read(x[0][i]);
		read(y[0][i]);
	}
	scanf("%d", &m);
	rep(i, m){
		read(x[1][i]);
		read(y[1][i]);
	}
	printf("%s\n", init() ? "YES" : "NO");
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++) 
using namespace std;
typedef long long int64;
int n, m, x, y, k, dx, dy;
int64 tot(0);
int main(){
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &k);
	rep(i, k){
		scanf("%d%d", &dx, &dy);
		if(!dx){
			if(dy > 0){
				tot += (m - y) / dy;
				y += (m - y) / dy * dy;
			}
			else{
				tot -= (y - 1) / dy;
				y -= (y - 1) / dy * dy;
			}
		}
		else if(!dy){
			if(dx > 0){
				tot += (n - x) / dx;
				x += (n - x) / dx * dx;
			}
			else{
				tot -= (x - 1) / dx;
				x -= (x - 1) / dx * dx;
			}
		}
		else{
			int S;
			if(dx > 0)
				S = (n - x) / dx;
			else
				S = -(x - 1) / dx;
			if(dy > 0)
				S = min(S, (m - y) / dy);
			else
				S = min(S, -(y - 1) / dy);
			tot += S;
			x += S * dx;
			y += S * dy;
		}
	}
	printf("%I64d\n", tot);
	return 0;
}


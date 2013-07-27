#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define MAXN 100100
#define rep(i, n) for(int i = 1; i <= n; ++i)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

int n, d, t[MAXN], v[MAXN];
double a, T0, V0, TL;

int main(){
	scanf("%d%lf%d", &n, &a, &d);
	T0 = V0 = 1e20;
	rep(i, n){
		scanf("%d%d", &t[i], &v[i]);
		double time = (double)d * 2.0 / a;
		time = sqrt(time);
		if(time * a <= v[i]){
			if(time + t[i] - t[i - 1] > T0){
				T0 = 2 * V0 / a + T0;
				TL = T0 + (d - 0.5 * a * T0 * T0) / V0;
			}
			else{
				T0 = time;
				TL = time;
				V0 = v[i];
			}
		}
		else{
			time = (double)v[i] / a;
			if(time <= T0){
				T0 = time;
				TL = T0 + (d - 0.5 * a * T0 * T0) / v[i];
				V0 = v[i];
			}
			else{
				
			}
		}
		printf("%.10lf\n", TL + t[i]);
	}
	return 0;
}

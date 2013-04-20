#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <map>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n;
double p[100005], E[100005][2];
double muli, mulii, add;

int main(){
	scanf("%d", &n);
	muli = 1;
	mulii = 0;
	for(int i = 1; i <= n; ++i)
		scanf("%lf", &p[i]);
	for(int i = 1; i <= n; ++i){
		add *= p[i]; muli *= p[i]; mulii *= p[i];
		E[i][0] = E[i - 1][0] * (1 - p[i]) + E[i - 1][1] * (1 - p[i]);
		E[i][1] = add + muli * i * i + mulii * i;
		add += E[i][0] + (1 - p[i]) * i * i;
		muli += 1 - p[i];
		mulii -= (1 - p[i]) * i * 2;
	}
	printf("%.10lf\n", E[n][0] + E[n][1]);
	return 0;
}
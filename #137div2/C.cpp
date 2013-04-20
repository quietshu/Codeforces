#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#define LIM 10000001
#define MAXN 100010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, pn, tmp, prime[1000000], hash[LIM];
bool inp[LIM];

void init(){
	for(int i = 2; i < LIM; ++i){
		if(!inp[i])
			prime[++pn] = i, hash[i] = pn;
		for(int j = 1; j <= pn && prime[j] * i < LIM; ++j){
			inp[prime[j] * i] = 1;
			if(i % prime[j] == 0)
				break;
		}
	}
}

int fracUp[MAXN], fracDown[MAXN];
int pu[LIM], pd[LIM], outU[MAXN], outD[MAXN], maxP;
vector<int> ansu, ansd;

int main(){
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &fracUp[i]);
		tmp = fracUp[i];
		for(int j = 1; j <= pn && prime[j] * prime[j] <= tmp; ++j){
			while(tmp % prime[j] == 0){
				pu[j]++;
				tmp /= prime[j];
			}
		}
		if(tmp != 1)
			pu[hash[tmp]]++;
	}
	for(int i = 1; i <= m; ++i){
		scanf("%d", &fracDown[i]);
		tmp = fracDown[i];
		for(int j = 1; j <= pn && prime[j] * prime[j] <= tmp; ++j){
			while(tmp % prime[j] == 0){
				pd[j]++;
				tmp /= prime[j];
			}
		}
		if(tmp != 1)
			pd[hash[tmp]]++;
	}
	for(int i = 1; i <= pn; ++i){
		tmp = min(pu[i], pd[i]);
		pu[i] -= tmp;
		pd[i] -= tmp;
	}
/*
	long long mul = 1;
	for(int i = 1; i <= pn; ++i){
		while(pu[i]){
			while(pu[i] && mul * prime[i] < LIM){
				mul *= prime[i];
				pu[i]--;
			}
			if(pu[i]){
				ansu.push_back(mul);
				mul = 1;
			}
		}
	}
	ansu.push_back(mul);
	mul = 1;
	for(int i = 1; i <= pn; ++i){
		while(pd[i]){
			while(pd[i] && mul * prime[i] < LIM){
				mul *= prime[i];
				pd[i]--;
			}
			if(pd[i]){
				ansd.push_back(mul);
				mul = 1;
			}
		}
	}
	ansd.push_back(mul);
orz!!!!!!!!!!!!!!!!!!!!!!!!!!*/

//我是傻x！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
	
	for(int i = 1; i < MAXN; ++i)
		outU[i] = outD[i] = 1;
	for(int i = 1; i <= n; ++i){
		tmp = fracUp[i];
		for(int j = 1; j <= pn && prime[j] * prime[j] <= tmp; ++j){
			while(pu[j] && tmp % prime[j] == 0){
				outU[i] *= prime[j];
				tmp /= prime[j];
				pu[j]--;
			}
			while(tmp % prime[j] == 0)
				tmp /= prime[j];
		}
		if(tmp != 1 && pu[hash[tmp]]){
			pu[hash[tmp]]--;
			outU[i] *= tmp;
		}
		if(outU[i] > 1) ansu.push_back(outU[i]);
	}
	for(int i = 1; i <= m; ++i){
		tmp = fracDown[i];
		for(int j = 1; j <= pn && prime[j] * prime[j] <= tmp; ++j){
			while(pd[j] && tmp % prime[j] == 0){
				outD[i] *= prime[j];
				tmp /= prime[j];
				pd[j]--;
			}
			while(tmp % prime[j] == 0)
				tmp /= prime[j];
		}
		if(tmp != 1 && pd[hash[tmp]]){
			pd[hash[tmp]]--;
			outD[i] *= tmp;
		}
		if(outD[i] > 1) ansd.push_back(outD[i]);
	}
	if(ansu.empty()) ansu.push_back(1);
	if(ansd.empty()) ansd.push_back(1);
	cout << ansu.size() << " " << ansd.size() << endl;
	for(int i = 0; i < ansu.size(); ++i)
		printf("%d ", ansu[i]);
	puts("");
	for(int i = 0; i < ansd.size(); ++i)
		printf("%d ", ansd[i]);
	return 0;
}
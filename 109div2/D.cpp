#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAX 100000 + 10
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << " = " << x << endl;
using namespace std;

bool O[MAX], Find;
int P[MAX], n, m, k;
char c;

int main(){
	scanf("%d%d", &n, &m);
	memset(P, 0, sizeof(P));
	memset(O, 0, sizeof(O));
	rep(i, m){
		scanf(" %c%d", &c, &k);
		Find = 0;
		if(c == '+'){
			if(O[k]){
				printf("Already on\n");
				continue;
			}
			for(int j = 2; j * j <= k; j++){
				if(k % j == 0 && P[j]){
					printf("Conflict with %d\n", P[j]);
					Find = 1;
					break;
				}
				if(k % j == 0 && P[k / j]){
					printf("Conflict with %d\n", P[k / j]);
					Find = 1;
					break;
				}
			}
			if(!Find && P[k]){
				printf("Conflict with %d\n", P[k]);
				Find = 1;
			}
			if(Find)
				continue;
			for(int j = 2; j * j <= k; j++)
				if(k % j == 0)
					P[j] = P[k / j] = k;
			P[k] = k;
			O[k] = 1;
			printf("Success\n");
		}
		else{
			if(!O[k]){
				printf("Already off\n");
				continue;
			}
			for(int j = 2; j * j <= k; j++)
				if(k % j == 0)
					P[j] = P[k / j] = 0;
			P[k] = 0;
			O[k] = 0;
			printf("Success\n");
		}
	}
	return 0;
}

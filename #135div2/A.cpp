#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define MAXL 1010
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int k, l, top, num[30];
char s[MAXL];

int main(){
	scanf("%d%s", &k, s);
	l = strlen(s);
	for(int i = 1; i <= l; ++i)
		num[s[i - 1] - 'a']++;
	for(int i = 0; i < 26; ++i)
		if(num[i] % k != 0){
			puts("-1");
			return 0;
		}
	for(int i = 0; i < 26; ++i)
		for(int j = 1; j <= num[i] / k; ++j){
			for(int t = 1; t <= k; ++t)
				s[(t - 1) * (l / k) + top] = 'a' + i;
			top++;
		}
	puts(s);
	return 0;
}
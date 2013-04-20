#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

long long p, d, l, r, tmp, res, power[100];
int bit, a[100], b[100];

int main(){
	cin >> p >> d;
	l = p - d; r = p;
	power[0] = 1;
	while(r){
		++bit;
		a[bit] = l % 10;
		b[bit] = r % 10;
		l /= 10;
		r /= 10;
		power[bit] = power[bit - 1] * 10;
	}
	for(int i = bit; i; --i){
		res = res * 10 + b[i];
		tmp = power[i - 1] - 1 + power[i - 1] * res;
		if(tmp >= p - d && tmp <= p){
			cout << tmp << endl;
			return 0;
		}
		tmp = power[i - 1] - 1 + power[i - 1] * (res - 1);
		if(tmp >= p - d && tmp <= p){
			cout << tmp << endl;
			return 0;
		}
	}
	return 0;
}
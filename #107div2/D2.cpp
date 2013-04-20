#include <iostream>
#include <cstdio>
#define mod 1000000007
using namespace std;

int n, m, k, ans;

int power(int a, int b){
	if(b == 0)
		return 1;
	int q = power(a, b / 2);
	q = q * q % mod;
	if(b & 1 == 1)
		q = q * a % mod;
	return q;
}

int main(){
	cin >> n >> m >> k;
	if(k > n)
		ans = power(m, n);
	else if(k == 1)
		ans = power(m, n);
	else if(m == 1)
		ans = 1;
	else if(k == n)
		ans = power(m, n / 2);
	else if(k % 2 == 0)
		ans = m;
	else ans = power(m, 2);
	cout << ans;
	return 0;
}

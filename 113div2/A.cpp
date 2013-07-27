#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

struct T{
	int n, t;
	bool operator < (const T &p) const{
		return n > p.n || (n == p.n && t < p.t);
	}
} a[200];

int n, k, sum, p;

int main(){
	cin >> n >> k;
	rep(i, n)
		cin >> a[i].n >> a[i].t;
	sort(a + 1, a + 1 + n);
	sum = 0;
	rep(i, n){
		sum++;
		if(a[i].n == a[i - 1].n && a[i].t == a[i - 1].t)
			p++;
		else{
			if(sum > k){
				cout << p << endl;
				return 0;
			}
			p = 1;
		}
	}
	cout << p << endl;
	return 0;
}

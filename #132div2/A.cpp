#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int n, m, a[100], b[100], ans, num;

int main(){
    cin >> n;
	rep(i, n)
		cin >> a[i];
	cin >> m;
	rep(j, m)
		cin >> b[j];
	rep(i, n)
		rep(j, m)
			if(b[j] % a[i] == 0){
				if(b[j] / a[i] > ans)
					ans = b[j] / a[i], num = 1;
				else if(b[j] / a[i] == ans)
					num++;
			}
	cout << num << endl;
	return 0;
}

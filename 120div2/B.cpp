#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#define rep(i, n) for(int i = 1; i <= n; i++)
#define debug(x) cout << #x << "=" << x << endl;
using namespace std;

double x1, y, r1, x2, y2, r2, dis;

int main(){
	cin >> x1 >> y >> r1 >> x2 >> y2 >> r2;
	dis = sqrt((x1 - x2) * (x1 - x2) + (y - y2) * (y - y2));
	if(dis <= r1 + r2){
		puts("0.000000000000000");
		return 0;
	}
	printf("%.15lf\n", (dis - r1 - r2) / 2.0);
	return 0;
}

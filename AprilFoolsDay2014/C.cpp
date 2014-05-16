#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a, b, c, d, e, x;
int main()
{
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	x = min(a, b);
	x = min(x, c >> 1);
	x = min(x, (int)d / 7);
	x = min(x, e >> 2);
	printf("%d\n", x);
	return 0;
}

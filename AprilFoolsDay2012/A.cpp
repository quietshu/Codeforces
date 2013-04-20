#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int dit[10000], ans;

int main(){
	char a[1000], b[1000];
	cin >> a >> b;
	int len = max(strlen(a), strlen(b)), d[1000];
	int la = strlen(a), lb = strlen(b);
	for(int i = 1; i <= la; ++i)
		d[len - i + 1] = a[la - i] - '0';
	for(int i = 1; i <= lb; ++i)
		d[len - i + 1] += b[i - 1] - '0';
	for(int i = len; i >= 1; i--){
		d[i - 1] += d[i] / 10;
		d[i] %= 10;
	}
	if(d[0]) ans = d[0];
	for(int i = 1; i <= len; ++i)
		ans = ans * 10 + d[i];
	cout << ans;
}
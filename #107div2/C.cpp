#include <iostream>
#include <cstdio>
using namespace std;

typedef long long int64;

int64 q, tot = 1, s = 1;

int main(){
	cin >> q;
	while(1){
		bool can_div = 0;
		for(int64 i = 2; i * i <= q; i++)
			if(q % i == 0){
				if(tot <= 2)
					s *= i;
				tot++;
				q /= i;
				can_div = 1;
				break;
			}
		if(!can_div)
			break;
	}
	if(tot == 1)
		printf("1\n0");
	else
		if(tot == 2)
			printf("2");
		else{
			printf("1\n");
			cout << s;
		}
	return 0;
}

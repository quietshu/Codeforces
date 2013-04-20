#include <iostream>
#include <cstring>
#include <cstdio>
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
struct nbook{
	char name[50];
	int s, taxi, pizza, girls;
} p[150];

int n, num[10], T = 0, P = 0, G = 0;

void read(char *name){
	char c = getchar();
	int n = 0;
	while(!isalpha(c))
		c = getchar();
	while(isalpha(c)){
		name[n++] = c;
		c = getchar();
	}
}

void read_num(int *num){
	char c = getchar();
	int n = 1;
	while(c < '0' || c > '9')
		c = getchar();
	rep(i, 6){
		num[n++] = c - '0';
		c = getchar();
		while(c == '-')
			c = getchar();
	}
}

int main(){
	scanf("%d", &n);
	rep(i, n){
		scanf("%d", &p[i].s);
		read(p[i].name);
		rep(j, p[i].s){
			read_num(num);
			bool _taxi = 1;
			rep(k, 5)
				if(num[k] != num[k + 1]){
					_taxi = 0;
					break;
				}
			if(_taxi)
				p[i].taxi++;
			else{
				bool _pizza = 1;
				rep(k, 5)
					if(num[k] <= num[k + 1]){
						_pizza = 0;
						break;
					}
				if(_pizza)
					p[i].pizza++;
				else
					p[i].girls++;
			}
		}
		if(!T || p[i].taxi >= p[T].taxi)
			T = i;
		if(!P || p[i].pizza >= p[P].pizza)
			P = i;
		if(!G || p[i].girls >= p[G].girls)
			G = i;
	}
	printf("If you want to call a taxi, you should call: ");
	rep(i, n)
		if(p[i].taxi == p[T].taxi){
			printf("%s", p[i].name);
			if(i < T)
				printf(", ");
		}
	printf(".\n");
	printf("If you want to order a pizza, you should call: ");
	rep(i, n)
		if(p[i].pizza == p[P].pizza){
			printf("%s", p[i].name);
			if(i < P)
				printf(", ");
		}
	printf(".\n");
	printf("If you want to go to a cafe with a wonderful girl, you should call: ");
	rep(i, n)
		if(p[i].girls == p[G].girls){
			printf("%s", p[i].name);
			if(i < G)
				printf(", ");
		}
	printf(".");
	return 0;
}

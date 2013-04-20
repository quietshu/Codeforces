/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : A.cpp
*	Creation Time : 2013/04/13 20:11:46
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int n, id;
map<int, int> t;

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &id);
        if(id)
            t[id]++;
    }
    int cnt = 0;
    for(map<int, int>::iterator it = t.begin(); it != t.end(); ++it)
        if(it->second == 2)
            ++cnt;
        else if(it->second > 2){
            puts("-1");
            return 0;
        }
    printf("%d\n", cnt);
    return 0;
}

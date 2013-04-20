/*
*	Copyright (C) Ds ds303077135@gmail.com
*	File Name     : B.cpp
*	Creation Time : 2013/04/13 20:25:46
*	Environment   : OS X 10.8
*/
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#define p {printf("<");rep(i,bl)printf("%c",block[i-1]);printf(">\n");bl=0;}
#define rep(i, n) for(int i = 1; i <= n; ++i)
using namespace std;

int l, bl;
char s[100010], block[100010];

int main(){
    cin.getline(s, 100010);
    l = strlen(s);
    s[l] = '"'; ++l; s[l] = '\0';

    bool q = 0;
    bl = 0;
    for(int i = 0; i < l; ++i){
        if(s[i] == '"'){
            if(q) p
            else if(bl) p
            q = !q;
        }
        else{
            if(q)
                block[bl++] = s[i];
            else{
                if(s[i] == ' ' && bl) p
                else if(s[i] != ' ') block[bl++] = s[i];
            }
        }
    }
    return 0;
}

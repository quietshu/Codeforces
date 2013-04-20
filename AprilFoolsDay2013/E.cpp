/*
 * =====================================================================================
 *
 *       Filename:  E.cpp
 *
 *    Description:  E
 *
 *        Version:  1.0
 *        Created:  04/02/2013 00:38:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shu Ding (QuietGalaxy), ds303077135@Gmail.com
 *   Organization:  NONE
 *
 * =====================================================================================
 */

#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int num = 0, tot = 0;
    char c = getchar();
    while(c == 'H' || c == 'Q'){
        if(c == 'Q') ++num;
        if(c == 'H'){
            if(num & 1){
                cout << "No" << endl;
                return 0;
            }
            num = 0;
        }
        ++tot;
        c = getchar();
    }
    puts(num == 1 ? "No" : "Yes");
}

#include <bits/stdc++.h>
using namespace std;

const int k = 69420;

int req(int a) {
    int b = 0;
    int bt = 30;
    while((a&(1<<bt)) == 0) {
        bt--;
    }
    int mn = bt;
    bt = 30;
    while((k&(1<<bt)) == 0) bt--;
    mn = min(bt, mn);
    //cout << bt << ' ';
    for(int j = 0; j <= bt; j++) {
        //Opposite of a, otherwise same as a.
        if(k<<j) b += (a&(1<<j)) ^ (1<<j);
        else b += a&(1<<j);
    }
    return b;
}

int main () {
    for(int i = 0; i < 20; i++) {
        int r = rand()%100000;
        cout << (r^(r^k)) << ' ' << (r^req(r)) << '\n';
    }
}
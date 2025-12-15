#include <bits/stdc++.h>
using namespace std;


double pow(double x, int n) {
    double p = x, tot = 1;
    while(n) {
        if(n & 1) tot *= p;
        p *= p;
        n >>= 1;
    }

}
double myPow(double x, int n) {
    
    if(n < 0) return (double) 1.00 / pow(x, abs(n));
    return pow(x, abs(n));
}

int main() {

}
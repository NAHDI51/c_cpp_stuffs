#include <bits/stdc++.h>
using namespace std;

int fac(int n) {
    if(n == 0 || n == 1) return 1;
    return n * fac(n-1);
}
int nCr(int n, int r) {
    if(r < 0 || r > n) return 0;
    if(r == 0) return 1;
    if(r == 1) return n;
    return nCr(n-1, r) + nCr(n-1, r-1);
}

/*
int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    int cnt = 10;
    for(int i = 2; i <= n; i++) cnt += (nCr(10, i) * fac(i)) - (nCr(10, i-1) * (fac(i-1))) + (nCr(9, i-2) * fac(i-1));
    return cnt;
}
*/
int countNumbersWithUniqueDigits(int n) {
    if(n == 0) return 1;
    int dp[9];
    dp[0] = 1, dp[1] = 9;
    for(int i = 2; i <= n; i++) dp[i] = dp[i-1] * (10-i+1);
    int cnt = 0;
    for(int i = 0; i <= n; i++) cnt += dp[i];
    return cnt;
}

int main() {

}
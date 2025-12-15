#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    if(r == 1) return n;
    if(r == 0 || n == r) return 1;
    return nCr(n-1,r-1) + nCr(n-1,r);
}
int dp2[11];
int dp[11][11];
int dynamic(int n, int t) {
    if(t == 1) return (n % 10 == 0) ? 0 : 1;
    if(dp2[t] != -1) return dp2[t];

    int div = (int) pow(10, t-1);
    int ext;
    if(n / div == 1) ext = (n % div) + 1;
    else if(n / div == 0) ext = 0;
    else ext = div;
    dp2[t] = (dp[t-1][t-1] * (n / div)) + ext + dynamic(n % div, t-1);
    //cout << n << '\t' << div << '\n';
    return dp2[t];
}

int countDigitOne(int n) {
    memset(dp, 0, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));

    for(int i = 1; i < 11; i++) for(int j = 1; j <= i; j++) 
        dp[j][i] = ((nCr(i, j) * pow(9, i-j)) * j) + dp[j-1][i];

    int t = 1;
    while((n % (int) pow(10, t)) != n)  t++;
    return dynamic(n, t);
    return 0;
}

int main() {
    int n;
    cin >> n;
    cout << countDigitOne(n) << '\n';
}
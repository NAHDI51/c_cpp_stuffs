#include <bits/stdc++.h>
using namespace std;

//Total turn that has ended with 1 late + 2 lates + present + absent
#define mod 1000000007
int checkRecord(int n) {
    if(n == 1) return 3;

    long long present = 1, one_late = 1, two_late = 0;
    long long absent;

    int dp[100001];
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        long long prz = present, lt1 = one_late;
        if(i == n) {
            absent = (n * present) % mod, absent %= mod;
            absent += (n * one_late) % mod, absent %= mod;
            absent += (n * two_late) % mod, absent %= mod;
        }
        present += (one_late+two_late) % mod, present %= mod;
        one_late = prz, one_late %= mod;
        two_late = lt1, two_late %= mod;
        dp[i] = present;
        //cout << present << "  " << one_late << "  " << two_late << '\n';
    }
    //LALL, LLAL
    for(int j = 1, i = 4; i <= n; i++, j++) 
        absent += (2 * dp[j-1] * dp[n-i]) % mod, absent %= mod;

    //LLALL
    for(int j = 1, i = 5; i <= n; i++, j++)
        absent += (dp[j-1] * dp[n-i]) % mod, absent %= mod;

    return ((present%mod) + (absent%mod) + (one_late%mod) + (two_late%mod)) % mod;
}

int main() {
    int n;
    cin >> n;
    cout << checkRecord(n) << '\n';
}
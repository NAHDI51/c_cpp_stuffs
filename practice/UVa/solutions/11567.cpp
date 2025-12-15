/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while(scanf("%d\n", &n) == 1) {
        int step = 0;
        while(n != 0 && n%2 == 0) n /= 2, step++;
        while(n) {
            auto l = __builtin_ctz(n-1), r = __builtin_ctz(n+1);
            if(l >= r) {
                n = (n-1) >> l;
                step += l;
            } else {
                n = (n+1) >> r;
                step += r;
            }

            step++;
            if(n == 1) step++, n--;
        }
        cout << step << '\n';
    }
}
*/

#include <stdio.h>
long long check(long long n) {
    if(n == 3)  return 2;
    if(n-1 == 0)    return n-1;
    int cnt = 0;
    long long tn;
    tn = n+1;
    while(tn%2 == 0 && tn)
        tn /= 2, cnt++;
    tn = n-1;
    while(tn%2 == 0 && tn)
        tn /= 2, cnt--;
    return cnt > 0 ? (n+1) : (n-1);
}
long long sol(long long n) {
    if(n <= 1)  return n;
    if(n%2)
        return sol(check(n))+1;
    else
        return sol(n/2)+1;
}
int main() {
    long long n;
    while(scanf("%lld", &n) == 1)
        printf("%lld\n", sol(n));
    return 0;
}
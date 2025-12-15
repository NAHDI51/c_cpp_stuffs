#include <bits/stdc++.h>
using namespace std;


int arr[101];
bool dp[10001];
void f(int size, int numb) {
    dp[0] = 1;
    for(int i = 0; i < size; i++) {
        for(int j = 10000; j >= 0; j--)
            if(dp[j]) dp[j+arr[i]] = true;
    }
    int ind = 5001 - numb;
    while(!dp[ind]) ind++;

    double ans = ((double) numb / (double) (ind+numb)) * 100.00;
    //cout << ans << '\n';
    //if((((int)(ans*1000) % 10) >= 5)) ans += 0.01;
    printf("%0.2lf\n", ans);
}

int main() {
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) return 0;
        double num;
        bool trig = false;
        for(int i = 0; i < a; i++) {
            if((i+1) == b) {
                cin >> num;
                num *= 100;
                trig = true;
            }
            else {
                double m;
                cin >> m;
                m *= 100;
                arr[i] = m;
                if(trig) arr[i-1] = arr[i];
            }
        }
        int numb = num;
        if(numb > 5000) {
            cout << "100.00\n";
            continue;
        }
        memset(dp, 0, sizeof(dp));
        f(a-1, numb);
    }
}
#include <bits/stdc++.h>
using namespace std;

#define fore(i, a, b) for(int i = a; i <= b; i++)

int main() {
    int cnt = 0;
    fore(i, 100,200) {
        fore(j, 100, 200) {
            bool ok = true;
            auto a = i, b = j;
            while(a) {
                if((a%10 + b%10) > 9) ok = false;
                a /= 10, b /= 10;
            }
            if(ok) {
                cout << '(' << i << "," << j << ')' << ' ';
                cnt++;
            }
        }
    }
    cout << '\n';
    cout << "Total: " << cnt << '\n';
}
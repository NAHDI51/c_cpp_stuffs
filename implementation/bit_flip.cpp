#include <bits/stdc++.h>
using namespace std;

void f() {
    bool a = true;
    int n = 10;
    while(n--) {
        cout << a << '\t';
        a ^= true;
    }
    cout << '\n';
}

int main() {
    f();
}
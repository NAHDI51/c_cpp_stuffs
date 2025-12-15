#include <bits/stdc++.h>
using namespace std;

int main() {
    int inc = 0, dec=  0;
    vector<int> a(4);

    for(a[3] = 1; a[3] < 10; a[3]++) {
        for(a[2] = 0; a[2] < 10; a[2]++) {
            for(a[1] = 0; a[1] < 10; a[1]++) {
                if(a[3] > a[2] && a[2] > a[1]) dec++;
                if(a[3] < a[2] && a[2] < a[1]) inc++;
                
                cout << a[3] << a[2] << a[1] << "  ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
    cout << "Total increments: " << max(inc, dec) << '\n';
    cout << "Total decrements: " << min(inc, dec) << '\n';
    cout << "Difference: " << max(inc, dec) - min(inc, dec) << "[Answer]" << '\n';
}
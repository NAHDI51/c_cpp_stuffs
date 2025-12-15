#include <bits/stdc++.h>
using namespace std;

#define maxN 10001
#define maxLog 20
#define pow2(i) (1<<i)
void f(vector<int>& a) {
    int sparse[maxN][maxLog];
    for(int i = 0; i < maxN; i++) sparse[i][0] = a[i];

    for(int j = 1; j < maxLog; j++) 
        for(int i = 0; i+pow2(j) < maxN; i++)
            sparse[i][j] = sparse[i][j-1] + sparse[i+pow2(j-1)][j-1];
    
    int log[maxN];
    log[1] = 1; 
    for(int i = 2; i < maxN; i++) log[i] = log[i/2]+1; 

    auto query = [&sparse, &log] (int l, int r) -> int {
        int rng = r-l+1;
        int bt = log[rng];
        int sm = 0;
        for(int i = 0; i <= bt; i++) if(rng & pow2(i)) sm += sparse[l][i], l += pow2(i);
        return sm;
    };

    bool dec = true;
    while(dec) {
        cout << "Enter your range: ";
        int a, b;
        cin >> a >> b;
        if(a < 0 || b < 0) break;
        cout << "Range [" << a+1 << ", " << b+1 << ']' << " : " << query(a, b) << '\n';
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }   
    f(a);
}
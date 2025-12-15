#include <bits/stdc++.h>
using namespace std;

/*
Some notes on square root decomposition
=> each index on the square root array is i/len, if i is the index of the original array.

*/

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
using vi = vector<int>;

#define maxN 500005 
int b[maxN];

class sqd {
int n, len;
vi a;
public:
sqd(vi& a) {
    n = a.size(), len = sqrt(n+0.0)+1;
    this->a = a;
    forn(i, n) b[i/len] += a[i];
}
void upd(int i, int val) {
    b[i/len] = val-a[i];
    a[i] = val;
}
int q(int l, int r) {
    int cl = l/len, cr = r/len;
    int sm = 0;
    if(cl == cr) fore(i, l, r) sm += a[i];
    else {
    cl++;
    fore(i, l, cl*len-1) sm += a[i];
    fore(i, cl, cr-1) sm += b[i];
    fore(i, cr*len, r) sm += a[i];
    }
    return sm;
}
};  

#define f first 
#define s second 

int len;
class query {
pair<int,int> r;
public:
bool operator<(query& b) {
    auto a = *this;
    if(a.r.f == b.r.f) return (a.r.f/len & 1) ? a.r.s < b.r.s : a.r.s > b.r.s;
    return a.r < b.r;
}
};

int main( ){

}
#include <bits/stdc++.h>
using namespace std;

//This program illustrates the ordered interval set.

#define forn(i, n) for(int i = 0; i < n; i++)
using ii = pair<int, int>;
using ll = long long;
using pll = pair<ll,ll>;

#define s second
#define f first

#define MAX 1000000000000000002LL
#define MIN -MAX

#define mod 1000000007LL

//interval set.
class iset {

set<pll> st;
public:

iset() {
    st.insert({MAX,MAX}), st.insert({MIN,MIN});
}

iset(vector<pll> a) {
    st.insert({MAX, MAX}), st.insert({MIN, MIN});
    forn(i, a.size()) insert(a[i]);
}

void insert(pll a) {
    auto one = upper_bound(st.begin(), st.end(), pll{a.f, MAX});
    one--;

    //Full interval
    if(one->f <= a.f && a.s <= one->s) return;

    //overlap
    if(one->s >= a.f-1) a.f = one->f;

    auto two = upper_bound(st.begin(), st.end(), pll(a.s+1, MAX));
    two--;
    if(two == one) {
        st.erase(one), st.insert(a);
        return;
    }
    //Overlap
    if(two->f <= a.s+1) a.s = two->s;

    vector<set<pll>::iterator> rmv;
    for(auto i = one; i != two; i++) rmv.push_back(i);

    forn(i, rmv.size()) {

        if(rmv[i]->f == MAX && rmv[i]->s == MAX) continue;
        if(rmv[i]->f == MIN && rmv[i]->s == MIN) continue;

        st.erase(rmv[i]);
    }
    st.insert(a);
}

void print() {
    for(auto i = st.begin(); i != st.end(); i++) {
        if(i->f == MAX && i->s == MAX) continue;
        if(i->f == MIN && i->s == MIN) continue;

        cout << i->f << ' ' << i->s << '\n';
    }
    cout << '\n';
}

int query(ll a, ll b) {
    auto one = lower_bound(st.begin(), st.end(), pll{a, MIN});

    ll sm = 0;
    while(1) {
        if(one->s > b) break;
        ll rng = one->s - one->f + 1;
        sm += ((rng%mod) * ((rng-1)%mod) / 2LL) + (rng%mod); 
        sm %= mod;
        one++;
    }
    return sm;
}
};

/*
How to insert

We are given that the initial set is an disjoint interval set

First, we find the greatest element <= a.f. Call it one.

If it covers the full interval, we insert nothing and return.
If it doesn't overlap [e.g one.s < l-1], we don't need to do anything.
Otherwise, we update the interval.

Second, we find the greatest element <= a.s+1. Call it two.
If one = two, then we insert [one.f, r], erase(one) and return. (That means it doesn't overlap)
Otherwise, it overlaps, and we update the interval.

Next, remove everything in the range [one, two] and return, insert [one.f, two.s] and return.

*/


//Let's drive this out.
int main() {
    int n;
    cin >> n;

    iset it;
    forn(i,n) {
        int t;
        cin >> t;
        ll a, b;
        cin >> a >> b;

        if(t==1) it.insert({a,b});
        else cout << it.query(a,b) << '\n';
    }
}
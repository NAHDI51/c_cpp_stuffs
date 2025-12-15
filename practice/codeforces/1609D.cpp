#include <bits/stdc++.h>
using namespace std;


//Maintain a set of root sets.
//In each iteration, we we are to join some disjoint sets, we are 
//going to remove the previous two instances of entry with the sets,
//And then again enter the newly found set.
//Otherwise, we are to increment the total number of sets to count.

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> size(n+1, 1);
    vector<int> anc(n+1);
    for(int i = 0; i < anc.size(); i++) anc[i] = i;

    //Initially, all the integers are roots.
    set<pair<int ,int>, greater<pair<int, int>>> st;
    for(int i = 1; i < anc.size(); i++) st.insert({1, i});

    auto find = [&](int a) -> int {
        while(a != anc[a]) a = anc[a];
        return anc[a];
    };
    auto same = [&](int a, int b) -> bool {
        return find(a) == find(b);
    };
    auto join = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        st.erase({size[a], a});
        st.erase({size[b], b});
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        anc[b] = a;
        st.insert({size[a], a});
    };

    int comps = 1;
    while(k--) {
        int a, b;
        cin >> a >> b;
        if(!same(a, b)) join(a, b);
        else comps++;

        int c = 0, sm = 0;
        for(auto i = st.begin(); i != st.end(); i++) {
            if(c == comps) break;
            sm += i->first;
            c++;
        }
        
        cout << sm-1 << '\n';
    }

}
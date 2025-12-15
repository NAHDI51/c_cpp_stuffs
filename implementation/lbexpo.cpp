#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int, greater<int>> st;
    for(int i = 0; i < 10; i++) st.insert(i);
    st.erase(5);
    cout << (*st.upper_bound(5)) << '\n';
}
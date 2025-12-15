#include <bits/stdc++.h>
using namespace std;

//Flawed
/*
bool canJump(vector<int>& a) {
    vector<int> pref(a.size()+1);
    auto push = [&](int l, int r) -> void {
        if(l < pref.size()) pref[l]++;
        if(r < pref.size()) pref[r]--;
    };
    for(int i = 0; i < a.size(); i++) push(i+1, i+1+a[i]);
    for(int i = 1; i < pref.size(); i++) pref[i] += pref[i-1];

    return pref.back();
}
*/

bool canJump(vector<int>& a) {
    
}

int main() {

}
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>


using namespace std;

typedef long long ll;
ll a = 345873, b = (int)1e9+9;

//Rabin Karp #1
//Precomputes the value and then evaluates the table.
//Make h 1 based index and p 0 based index
//O(n)

vector<int> rabin_karp_1(string s, string t) {
    vector<ll> h(s.size()+1), p(s.size());
    h[0] = p[0] = 1;
    for(int i = 0 ; i < s.size(); i++) 
        h[i+1] = (((h[i] * a) % b) + s[i]) % b;
    for(int i = 1 ; i < s.size(); i++)
        p[i] = (p[i-1]* a) % b;
    
    //Returns the hashval of any range
    auto hashval = [&] (int l, int r) -> ll {
        return (h[r+1] - ((h[l] * p[r-l+1]) % b) + b) % b;
    };

    ll hash = 0;
    for(int i = 0 ; i < t.size(); i++)
        hash = ((hash * a) % b + t[i]) % b;

    cout << "hash value: " << hash << "\n\n";
    vector<int> ans;
    for(int i = t.size()-1, j = 0; i < s.size(); i++, j++) {
        if(hash == hashval(j, i))
            ans.push_back(j);
        
        cout << s.substr(j, t.size()) << '\t' << hashval(j, i) << '\n';
    }
    cout << '\n';
    return ans;
    
}

//Rabin_karp_2
//Computes the values like a window and evaluates.
//O(n)
/*
algorithm:
APPEND(S[I]), appends infront, polynomically
DELETE(S[J]), deletes infront, polynomically
*/
vector<int> rabin_karp_2(string s, string t) {
    ll th = 0;
    for(int i = 0 ; i < t.size(); i++)
        th = ((th*a) % b + t[i]) % b;
    
    ll sh = 0;
    for(int i = 0 ; i < t.size()-1; i++)
        sh = ((sh*a) % b + s[i]) % b;
    
    auto ModPow = [&](ll x, ll y) -> ll {
        ll res = 1, num = x;
        while(y) {
            if(y & 1) 
                res *= num, res %= b;
            num *= num, num %= b;
            y >>= 1;
        }
        return res;
    };
    ll pow = ModPow(a, t.size()-1);
    auto append = [&] (int num) -> void{
        sh = ((sh*a) % b + num) % b;
    };
    auto remove = [&] (int num) -> void {
        sh = (sh + - (pow * num) % b + b) % b;
    };
    vector<int> ans;
    cout << "Hash value: " << th << "\n\n";
    for(int i = t.size()-1, j = 0; i < s.size(); i++, j++) {
        append(s[i]);
        if(sh == th)
            ans.push_back(j);
        cout << s.substr(j, t.size()) << '\t' << sh << '\n';
        remove(s[j]);
    }
    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;
    for(auto x : rabin_karp_2(s, t))
        cout << s.substr(x, t.size()) << '\n';
}
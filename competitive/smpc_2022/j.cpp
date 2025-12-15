#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using table = unordered_map<unsigned long, int>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define FLAG cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 10000000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

// Function to return ASCII
// value of a character
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// Function to convert a number
// from given base to decimal number
int toDeci(string str, int base)
{
    // Stores the length
    // of the string
    int len = str.size();
 
    // Initialize power of base
    int power = 1;
 
    // Initialize result
    int num = 0;
 
    // Decimal equivalent is str[len-1]*1
    // + str[len-2]*base + str[len-3]*(base^2) + ...
    for (int i = len - 1; i >= 0; i--) {
 
        // A digit in input number must
        // be less than number's base
        if (val(str[i]) >= base) {
            printf("Invalid Number");
            return -1;
        }
 
        // Update num
        num += val(str[i]) * power;
 
        // Update power
        power = power * base;
    }
 
    return num;
}
 
// Function to return equivalent
// character of a given value
char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
// Function to convert a given
// decimal number to a given base
string fromDeci(int base, int inputNum)
{
    // Store the result
    string res = "";
 
    // Repeatedly divide inputNum
    // by base and take remainder
    while (inputNum > 0) {
 
        // Update res
        res += reVal(inputNum % base);
 
        // Update inputNum
        inputNum /= base;
    }
 
    // Reverse the result
    reverse(res.begin(), res.end());
 
    return res;
}
 
// Function to convert a given number
// from a base to another base
void convertBase(string s, int a, int b)
{
    // Convert the number from
    // base A to decimal
    int num = toDeci(s, a);
 
    // Convert the number from
    // decimal to base B
    string ans = fromDeci(b, num);
 
    // Print the result
    if(ans.sz() <= 7) printf("%7s\n", ans.c_str());
    else cout << "  ERROR\n";
}

bool solve(){
    string s;
    int from, to;
    cin >> s;
    cin >> from >> to;
    if(from == 0 && to == 0) return false;
    convertBase(s, from, to);
    return true;
}

int main() {
    while(1) {
        if(!solve()) return 0;
    }
}
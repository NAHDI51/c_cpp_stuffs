#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ll long long
#define sz size
#define maxN 
ll mod = 1000000007ll;

ll dp[52][35][35][2][2];
int vis[52][35][35][2][2];
ll lim;
ll cur;

int max(int a, int b) {
    return (a < b) ? b : a;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

inline static ll count(int pos, int c1, int c2, int start, int tight, char* s){
        if(pos == -1) {
            return (start && c1 == 17 && c1 == c2);
        }
        if(c1 <= max(17-lim, 0) || c2 <= max(17-lim, 0) || c1 >= min(17+lim, 34) || c2 >= min(17+lim, 34)) {
            dp[pos][c1][c2][start][tight] = 0;
            return dp[pos][c1][c2][start][tight];
        }
        if(!tight && vis[pos][c1][c2][start][tight] == cur) return dp[pos][c1][c2][start][tight];
        vis[pos][c1][c2][start][tight] = cur;

        dp[pos][c1][c2][start][tight] = 0;
        int lim = (tight) ? s[pos]-'0' : 9;

        for(int i = 0; i <= lim; i++) {
            dp[pos][c1][c2][start][tight] += count(pos-1, c1-(i==6)+(i==3), c2-(i==9)+(i==6), start || i==3 || i==6 || i==9, tight && (i == lim), s);
            dp[pos][c1][c2][start][tight] %= mod;
        }
        // cout << ret << ' ' << pos << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << tight << '\n';
        return dp[pos][c1][c2][start][tight];
    };

char a[100], b[100];
void decrese(){
    int len = strlen(a) - 1;
    if(a[len] != '0'){
        a[len] = (a[len] - '0' - 1) + '0';
    }
    else {
        while(1){
            if(a[len] == '0'){
                a[len] = '9';
                len--;
            }  
            else {
                a[len] = (a[len] - '0' - 1) + '0';
                break;
            }
        }
    }
}
inline void rev(char* s) {
    if (!s) return;
    int n = 0;
    while (s[n] != '\0') ++n;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}
void solve() {
    scanf("%s %s", a, b);
    rev(a), rev(b);
    // printf("%s %s\n", a, b);
    // clear();

    ll c1 = 0;
        int bs = strlen(b);
        lim = bs/3+1;
        cur++;
        c1 = count(bs-1, 17,17,0,1, b);
    ll c2 = 0;
        // clear();
        int as = strlen(a);
        lim = as/3+1;
        cur++;
        c2 = count(as-1, 17,17,0,1, a);
    ll ans = c1 - c2;
    if(ans < 0) ans += mod;

    // cout << c1 << ' ' << c2 << ' ';
    printf("%lld\n", ans);
}

int main() {
    //Sublime
    // init();
    // FASTIO;

    cur = 0;
    int t;
    scanf("%d", &t);
    while(t--) solve();
}


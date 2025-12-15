#include <bits/stdc++.h>
using namespace std;


#define MIN INT_MIN
void f(vector<vector<vector<long>>> v) {
    vector<vector<vector<long>>> a(v.size()+1, vector<vector<long>>(v[0].size()+1, vector<long>(v[0][0].size()+1, 0)));

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < a[0].size(); j++) {
            for(int k = 1; k < a[0][0].size(); k++) {
                a[i][j][k] =  v[i-1][j-1][k-1] +                    //Initial
                a[i-1][j][k] + a[i][j-1][k] + a[i][j][k-1] -        //First coordinates
                a[i-1][j-1][k] - a[i][j-1][k-1] - a[i-1][j][k-1] +  //Second coordinates
                a[i-1][j-1][k-1];                                   //All excluded. 
            }
        }
    }
    
    long mx = MIN;
    long tmp;
    for(int p = 1; p < a.size(); p++) {
        for(int q = 1; q < a[0].size(); q++) {
            for(int r = 1; r < a[0][0].size(); r++) {
                for(int i = p; i < a.size(); i++) {
                    for(int j = q; j < a[0].size(); j++) {
                        for(int k = r; k < a[0][0].size(); k++) {

                            tmp = a[i][j][k]                                      //Initial
                            -a[p-1][j][k] - a[i][q-1][k] - a[i][j][r-1]           //First coordinates
                            + a[p-1][q-1][k] + a[p-1][j][r-1] + a[i][q-1][r-1]    //Second coordinates
                            - a[p-1][q-1][r-1];                                   //ALl excluded.

                            mx = max(tmp, mx);
                        }
                    }
                }
            }
        }
    } 
    cout << mx << "\n" ;
}


int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<vector<vector<long>>> vvv(a, vector<vector<long>>(b, vector<long>(c, 0)));
        for(int i = 0; i < a; i++) 
            for(int j = 0; j < b; j++)
                for(int k = 0; k < c; k++)
                    cin >> vvv[i][j][k];
        f(vvv);
        if(t) puts("");
    }
}


/*
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<vector<vector<long>>> m(a, vector<vector<long>>(b, vector<long>(c, 0)));
        
        for (int i=0;i<a;++i) for (int j=0;j<b;++j) for (int k=0;k<c;++k) {
            long long g; cin>>g;
            if (i>0) g+=m[i-1][j][k];
            if (j>0) g+=m[i][j-1][k];
            if (k>0) g+=m[i][j][k-1];
            if (i>0 && j>0) g-=m[i-1][j-1][k];
            if (j>0 && k>0) g-=m[i][j-1][k-1];
            if (i>0 && k>0) g-=m[i-1][j][k-1];
            if (i>0 && j>0 && k>0) g+=m[i-1][j-1][k-1];
            m[i][j][k]=g;
        }
        long long max_sum = INT_MIN;
        for (int i=0;i<a;++i) for (int j=0;j<c;++j) for (int k=0;k<c;++k) 
        for (int i1=i;i1<b;++i1) for (int j1=j;j1<b;++j1) for (int k1=k;k1<c;++k1)  {
            long long s = m[i1][j1][k1];
            if (i>0) s-=m[i-1][j1][k1];
            if (j>0) s-=m[i1][j-1][k1];
            if (k>0) s-=m[i1][j1][k-1];
            if (i>0 && j>0) s+=m[i-1][j-1][k1];
            if (j>0 && k>0) s+=m[i1][j-1][k-1];
            if (i>0 && k>0) s+=m[i-1][j1][k-1];
            if (i>0 && j>0 && k>0) s-=m[i-1][j-1][k-1];
            if (s>max_sum) max_sum = s;
        }
    }
}
*/
#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]]++;
    }
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    int ans=71;
    for(double i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            double d = ((v[j]-v[i])*1.0)/(1.0*(j-i));
            int itm = 0;;
            for(double k = 0; k < n; k++){
                double dif=(v[k]-v[i])-(k-i)*d;
                dif = abs(dif);
                if(dif >= 0.000000000001){
                    itm++;
                }
            }
            ans=min(itm,ans);
        }
    }
    cout<<ans<<endl;
    return;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
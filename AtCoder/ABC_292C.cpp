#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> sieve(n+1,-1);
    sieve[1] = 1;
    for(int i = 2;i <= n;i++){
        for(int j = i;j <= n;j+=i){
            if(sieve[j] == -1){
                sieve[j] = i;
            }
        }
    }
    vector<ll> splits(n+1,1);
    splits[1] = 1;
    for(int i = 2;i <= n;i++){
        ll x = i;
        map<ll,ll> powers;
        while(x != 1){
            powers[sieve[x]]++;
            x /= sieve[x];
        }
        for(pair<ll,ll> p:powers){
            splits[i] *= (p.second+1);
        }
    }
    ll ans = 0;
    for(int i = 1;i < n;i++){
        ans += (splits[i]*splits[n-i]);
    }
    cout<<ans<<"\n";
    return 0;
}
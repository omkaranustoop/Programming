#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;
int mod = 998244353;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<ll> a(n),b(n);
    for(int i = 0;i < n;i++){
        cin>>a[i]>>b[i];
    }
    vector<vector<ll>> dp(n,vector<ll>(2));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 1;i < n;i++){
        if(a[i] != a[i-1]){
            dp[i][0] = (dp[i][0] + dp[i-1][0]) % mod;
        }
        if(a[i] != b[i-1]){
            dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
        }
        if(b[i] != a[i-1]){
            dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
        }
        if(b[i] != b[i-1]){
            dp[i][1] = (dp[i][1] + dp[i-1][1]) % mod;
        }
    }
    ll ans = (dp[n-1][0] + dp[n-1][1]) % mod;
    cout<<ans<<"\n";
    return 0;
}
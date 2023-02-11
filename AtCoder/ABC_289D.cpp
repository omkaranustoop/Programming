#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n;i++){
        cin>>v[i];
    }
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i = 0;i < m;i++){
        cin>>b[i];
    }
    int target;
    cin>>target;
    vector<int> dp(target+1,-1);
    dp[0] = 1;
    for(int i = 0;i < target;i++){
        //cerr<<"Here";
        if((binary_search(b.begin(),b.end(),i) == true) || dp[i] != 1){
            //cout<<"Continue";
            continue;
        }
        for(int x:v){
            dp[i+x] = 1;
        }
    }
    // for(int x:dp){
    //     cout<<x<<" ";
    // }
    if(dp[target] == 1){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
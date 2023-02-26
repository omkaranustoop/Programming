#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long double n;
    cin>>n;
    vector<int> v(5*n);
    for(int i = 0;i < 5*n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long double sum = 1e-8;
    for(int i = n;i < 4*n;i++){
        sum += v[i];
    }
    long double ans = sum/(3*n);
    cout<<setprecision(20)<<ans<<"\n";
    return 0;
}
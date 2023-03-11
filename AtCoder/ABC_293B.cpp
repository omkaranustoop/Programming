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
    vector<bool> marker(n+1);
    for(int i = 0;i < n;i++){
        if(marker[i+1] == false){
            marker[v[i]] = true;
        }
    }
    int cnt = 0;
    vector<int> ans;
    for(int i = 1;i <= n;i++){
        if(marker[i] == false){
            cnt++;
            ans.push_back(i);
        }
    }
    cout<<cnt<<"\n";
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int c;
    vector<vector<int>> setvals(m);
    for(int i = 0;i < m;i++){
        cin>>c;
        int x;
        for(int j = 0;j < c;j++){
            cin>>x;
            setvals[i].push_back(x);
        }
    }
    ll count = 0;
    for(int mask = 0;mask < (1<<m);mask++){
        set<int> vals;
        for(int i = 0;i < m;i++){
            if(mask&(1<<i)){
               for(int element:setvals[i]){
                vals.insert(element);
               }
            }
        }
        if(vals.size() == n){
            count++;
        }
    }
    cout<<count<<"\n";

    return 0;
}
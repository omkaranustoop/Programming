#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> pl(n+1);
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x == 1){
            pl[y]++;
        }
        else if(x == 2){
            pl[y] += 2;
        }
        else{
            if(pl[y] >= 2){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
        }
    }

    return 0;
}
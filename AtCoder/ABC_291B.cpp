#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool done = true;
    map<pair<int,int>, bool> seen;
    seen[make_pair(0,0)] = true;
    int x = 0, y = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'R'){
           x++;
        }
        else if(s[i] == 'L'){
           x--;
        }
        else if(s[i] == 'U'){
           y++;
        }
        else{
           y--;
        }
        if(seen[make_pair(x,y)]){
            done = false;
            break;
        }
        seen[make_pair(x,y)] = true;
    }
    if(done){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }

    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int ans;
    for(int i = 0;i < s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            ans = i+1;
            break;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
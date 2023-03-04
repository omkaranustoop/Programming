#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string ans = "";
    for(char ch:s){
        ans += toupper(ch);
    }
    cout<<ans<<"\n";

    return 0;
}
#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    for(int i = 0;i < s.size();i++){
        if(s[i] == '0'){
            s[i] = '1';
        }
        else{
            s[i] = '0';
        }
    }
    cout<<s<<"\n";

    return 0;
}
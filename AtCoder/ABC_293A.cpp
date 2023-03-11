#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    for(int i = 0;i < s.length();i+=2){
        char c = s[i];
        s[i] = s[i+1];
        s[i+1] = c;
    }
    cout<<s<<"\n";

    return 0;
}
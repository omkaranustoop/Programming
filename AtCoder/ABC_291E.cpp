#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> indegree(n+1);
    int u,v;
    map<pair<int,int>,bool>seen;
    vector<vector<int>> adjlist(n+1);
    for(int i = 0;i < m;i++){
        cin>>u>>v;
        if(seen[make_pair(u,v)])continue;
        seen[make_pair(u,v)] = true;
        indegree[v]++;
        adjlist[u].push_back(v);
    }
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    int curr = 1;
    vector<int> ans(n);
    bool done = true;
    while(!q.empty()){
        if(q.size() > 1){
            done = false;
            break;
        }
        int t = q.front();
        q.pop();
        ans[t-1] = curr++;
        for(int x:adjlist[t]){
            indegree[x]--;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }
    for(int i = 1;i <= n;i++){
        if(indegree[i] != 0)done = false;
    }
    if(!done){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
        for(int x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
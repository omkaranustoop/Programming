#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;
void dfs(int parent,int node, vector<vector<int>>& adj, vector<vector<int>>& reachables, map<int,bool>& seen){
    if(seen[node])return;
    seen[node] = true;
    if(node != parent){
        reachables[parent].push_back(node);
    }
    for(int x:adj[node]){
        if(!seen[x]){
            dfs(parent,x,adj,reachables,seen);
        }
    }
    return;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    int u,v;
    vector<vector<int>> seen(n+1,vector<int>(n+1));
    for(int i = 0;i < m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        seen[u][v] = true;
    }
    vector<vector<int>> reachables(n+1);
    map<int,bool> seen2;
    for(int i = 1;i <= n;i++){
        seen2.clear();
        dfs(i,i,adj,reachables,seen2);
    }
    ll count = 0;
    for(int i = 1;i <= n;i++){
        for(int j:reachables[i]){
            if(!seen[i][j]){
                count++;
                seen[i][j] = true;
            }
        }
    }
    cout<<count<<"\n";
    return 0;
}
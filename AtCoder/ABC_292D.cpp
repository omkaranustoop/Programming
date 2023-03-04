#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

void dfs(int node, vector<vector<int>>& adj, vector<int>& color, int curr){
    color[node] = curr;
    for(int x:adj[node]){
        if(color[x] == -1){
            // edges[curr]++;
            dfs(x,adj,color,curr);
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
    map<pair<int,int>,bool>seen;
    vector<pair<int,int>> alledges;
    for(int i = 0;i < m;i++){
        cin>>u>>v;
        alledges.push_back(make_pair(u,v));
        // if(seen[make_pair(u,v)] || seen[make_pair(v,u)])continue;
        // seen[make_pair(u,v)] = true;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int curr = 0;
    vector<int> color(n+1,-1);
    map<int,int> edges;
    for(int i = 1;i <= n;i++){
        if(color[i] == -1){
            dfs(i,adj,color,curr);
            curr++;
        }
    }
    map<int,int> nodes;
    for(int i = 1;i <= n;i++){
        nodes[color[i]]++;
    }
    for(pair<int,int> p:alledges){
        edges[color[p.first]]++;
    }
    bool done = true;
    for(pair<int,int> p:nodes){
        if(p.second != edges[p.first]){
            done = false;
            break;
        }
    }
    // for(pair<int,int> p:nodes){
    //     cout<<p.first<<" "<<p.second<<" "<<edges[p.first]<<"\n";
    // }
    if(done){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
    return 0;
}
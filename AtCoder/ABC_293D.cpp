#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

void colorall(int node, vector<vector<int>>& adj, vector<int>& nodecolor, int color){
   nodecolor[node] = color;
   for(int x:adj[node]){
    if(nodecolor[x] == -1){
        colorall(x,adj,nodecolor,color);
    }
   }
   return;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(2*n + 1);
    int a,b;
    char c,d;
    for(int i = 0;i < m;i++){
        cin>>a>>c>>b>>d;
        int firstnode, secondnode;
        if(c=='R'){
            firstnode = a;
        }
        else{
            firstnode = a+n;
        }
        if(d == 'R'){
            secondnode = b;
        }
        else{
            secondnode = b+n;
        }
        adj[firstnode].push_back(secondnode);
        adj[secondnode].push_back(firstnode);
    } 
    for(int i = 1;i <= n;i++){
        adj[i].push_back(i+n);
        adj[i+n].push_back(i);
    }
    int color = 0;
    vector<int> nodecolor(2*n + 1,-1);
    for(int i = 1;i <= 2*n;i++){
        if(nodecolor[i] == -1){
            colorall(i,adj,nodecolor,color);
            color++;
        }
    }
    vector<vector<int>> comps(color+1);
    //map<int,vector<int>>comps;
    for(int i = 1;i<=2*n;i++){
        comps[nodecolor[i]].push_back(i);
    }
    vector<ll> edgecount(color+1);
    for(int c = 0;c < color;c++){
        pair<int,vector<int>> p = make_pair(c,comps[c]);
        //pair<int,vector<int>>p:comps)
        ll cnt = 0;
        for(int x:p.second){
           cnt += adj[x].size();
        }
        edgecount[p.first] = cnt/2;
    }
    int x = 0, y = 0;
    for(int c = 0;c < color;c++){
        pair<int,ll> p = make_pair(c,edgecount[c]);
        //pair<int,ll> p:edgecount)
        ll edges = p.second;
        ll nodes = comps[p.first].size();
        if(edges == nodes){
            x++;
        }
        else{
            y++;
        }
    }
    cout<<x<<" "<<y<<"\n";
    return 0;
}
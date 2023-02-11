#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

void colour(int node, vector<int>& nodecolor, vector<vector<int>>& adjlist, int color){
    if(nodecolor[node] != -1)return;
    nodecolor[node] = color;
    for(int x:adjlist[node]){
        if(nodecolor[x] == -1){
            colour(x,nodecolor,adjlist,color);
        }
    }
    return;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> v(m);
    vector<vector<int>> adjlist(n+1);
    for(int i = 0;i < m;i++){
        cin>>v[i];
        adjlist[v[i]].push_back(v[i]+1);
        adjlist[v[i]+1].push_back(v[i]);
    }
    int color = 0;
    vector<int> nodecolor(n+1,-1);
    for(int i = 1;i <= n;i++){
        if(nodecolor[i] == -1){
            colour(i,nodecolor,adjlist,color);
            color++;
        }
    }
    map<int,vector<int>> colormap;
    for(int i = 1;i <= n;i++){
        colormap[nodecolor[i]].push_back(i);
    }
    for(int curr = 0;curr < color;curr++){
        vector<int> temp = colormap[curr];
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        for(int x:temp){
            cout<<x<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
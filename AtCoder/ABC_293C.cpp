#include<bits/stdc++.h>

using namespace std;
using ll = int64_t;

void dfs(int i, int j, int target, int &ways, int r, int c, set<int> dist,vector<vector<int>>& grid){
   dist.insert(grid[i][j]);
   if(i == r-1 && j == c-1){
    if(dist.size() == target)ways++;
    return;
   }
   if(i+1 >= 0 && i+1 < r){
    dfs(i+1,j,target,ways,r,c,dist,grid);
   }
   if(j+1 >= 0 && j+1 < c){
    dfs(i,j+1,target,ways,r,c,dist,grid);
   }
   return;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin>>h>>w;
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < w;j++){
            cin>>grid[i][j];
        }
    }
    int ways = 0;
    int target = h+w-1;
    set<int> distinct;
    dfs(0,0,target,ways,h,w,distinct,grid);
    cout<<ways<<"\n";

    return 0;
}
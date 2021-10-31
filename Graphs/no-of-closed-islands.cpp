#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void dfs(vector<vector<int>>& grid, int r,int c){
        if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || grid[r][c]==1){
            return ;
        }
        
        grid[r][c]=1;
        dfs(grid,r-1,c) ;
        dfs(grid,r+1,c) ;
        dfs(grid,r,c-1) ;
        dfs(grid,r,c+1);
        
    }
    
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(i==0 || j==0 || i==grid.size()-1 || j==grid[0].size()-1){
                    dfs(grid,i,j);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
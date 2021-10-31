#include <bits/stdc++.h>
using namespace std;

class Solution {
    
    void dfs(vector<vector<int>>& image,int sr,int sc,int color,int newColor){
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size()  || image[sr][sc]!=color){
            return;
        }
        image[sr][sc]=newColor;
        dfs(image,sr-1,sc,color,newColor);
        dfs(image,sr+1,sc,color,newColor);
        dfs(image,sr,sc-1,color,newColor);
        dfs(image,sr,sc+1,color,newColor);
        
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color=image[sr][sc];
        if(color!=newColor){
        dfs(image,sr,sc,color,newColor);
            
        }
        return image;
        
        
    }
};
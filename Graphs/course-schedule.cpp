#include <bits/stdc++.h>
using namespace std;
class Solution {
    
private: 
    bool dfs(int i,vector<int> &vis,vector<int> &pathVis,vector<int> adj[]){
        vis[i]=1;
        pathVis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)){
                return true;
                }
            }
            else if(pathVis[it]==1){
                return true;
            }
        }
        
        pathVis[i]=0;
        return false;
    }

public:
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)){
                    return false;
                }
            }
        }
        return true;
    }
};
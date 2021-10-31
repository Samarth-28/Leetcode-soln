#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<int> st;
    
    void dfs(vector<vector<int>>& rooms,vector<int> &vis,int node){
        vis[node]=1;
        for(auto it: rooms[node]){
            if(!vis[it]){
                dfs(rooms,vis,it);
            }
        }
    }
    
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> vis(rooms.size());
        dfs(rooms,vis,0);
        return rooms.size()==count(vis.begin(),vis.end(),1);
        
    }
};
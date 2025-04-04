//Undirected Graph Cycle
class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj,vector<int> &vis,vector<int> &parent){
        vis[node]=1;
        for(auto e:adj[node]){
            if(!vis[e]){
                parent[e]=node;
                if(dfs(e,adj,vis,parent)) return true;
            }else if(parent[e]!=node){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> vis(V,0);
        vector<int> parent(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,parent)){
                    return true;
                }
            }
        }
        return false;

    }
};
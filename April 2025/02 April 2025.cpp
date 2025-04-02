//BFS of graph
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        queue<int> q;
        q.push(0);
        vector<int> vis(adj.size(),0);
        vis[0]=1;
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto e:adj[node]){
                if(!vis[e]){
                    vis[e]=1;
                    q.push(e);
                }
            }

        }
        return ans;
    }
};
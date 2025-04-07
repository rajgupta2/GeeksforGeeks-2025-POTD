//Directed Graph Cycle
class Solution {
    public:

      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
          vector<vector<int>> adj(V);
          vector<int> indegree(V,0);
          for(auto e:edges){
              adj[e[0]].push_back(e[1]);
              indegree[e[1]]++;
          }
          vector<int> result;
          queue<int> q;
          for (int i = 0; i < V; i++) {
              if (indegree[i] == 0) {
                  q.push(i);
              }
          }
          while (!q.empty()) {
              int node = q.front();
              q.pop();
              result.push_back(node);

              for (auto it : adj[node]) {
                  indegree[it]--;
                  if (indegree[it] == 0)
                      q.push(it);
              }
          }

          if (result.size() != V) {
              return true;
          }

          return false;
      }
  };
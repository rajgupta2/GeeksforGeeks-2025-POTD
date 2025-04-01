/*
DFS of Graph
*/
class Solution {
    public:
      void addEdge(vector<vector<int>> &adj, int s, int t)
  {
      adj[s].push_back(t);
      adj[t].push_back(s);
  }

  // Recursive function for DFS traversal
  void dfsRec(vector<vector<int>> &adj, vector<bool> &visited, int s, vector<int> &res)
  {
      // Mark the current vertex as visited
      visited[s] = true;

      res.push_back(s);

      // Recursively visit all adjacent vertices that are not visited yet
      for (int i : adj[s])
          if (visited[i] == false)
              dfsRec(adj, visited, i, res);
  }

  // Main DFS function to perform DFS for the entire graph
  vector<int> dfs(vector<vector<int>> &adj)
  {
      vector<bool> visited(adj.size(), false);
      vector<int> res;
      // Loop through all vertices to handle disconnected graph
      for (int i = 0; i < adj.size(); i++)
      {
          if (visited[i] == false)
          {
              // If vertex i has not been visited,
              // perform DFS from it
              dfsRec(adj, visited, i, res);
          }
      }

      return res;
  }
  };
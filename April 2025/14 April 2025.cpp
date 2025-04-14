//Alien Dictionary
class Solution {
    public:
      string findOrder(const vector<string>& words) {

      // Adjacency list
      vector<vector<int>> graph(26);

      // In-degree of each character
      vector<int> inDegree(26, 0);

      // Tracks which characters are present
      vector<bool> exists(26, false);

      // Mark existing characters
      for (const string& word : words) {
          for (char ch : word) {
              exists[ch - 'a'] = true;
          }
      }

      // Build the graph from adjacent words
      for (int i = 0; i + 1 < words.size(); ++i) {
          const string& w1 = words[i];
          const string& w2 = words[i + 1];
          int len = min(w1.length(), w2.length());
          int j = 0;

          while (j < len && w1[j] == w2[j]) ++j;

          if (j < len) {
              int u = w1[j] - 'a';
              int v = w2[j] - 'a';
              graph[u].push_back(v);
              inDegree[v]++;
          } else if (w1.size() > w2.size()) {

              // Invalid input
              return "";
          }
      }

      // Topological sort
      queue<int> q;
      for (int i = 0; i < 26; ++i) {
          if (exists[i] && inDegree[i] == 0) {
              q.push(i);
          }
      }

      string result;
      while (!q.empty()) {
          int u = q.front(); q.pop();
          result += (char)(u + 'a');

          for (int v : graph[u]) {
              inDegree[v]--;
              if (inDegree[v] == 0) {
                  q.push(v);
              }
          }
      }

      // Check, there was a cycle or not
      for (int i = 0; i < 26; ++i) {
          if (exists[i] && inDegree[i] != 0) {
              return "";
          }
      }

      return result;
  }
  };
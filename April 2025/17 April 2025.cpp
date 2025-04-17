//Minimum Weight Cycle
class Solution
{
public:
    vector<vector<vector<int>>> constructadj(int V, vector<vector<int>> &edges)
    {
        vector<vector<vector<int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        return adj;
    }
    int minCycle;

    void dfs(int u, int parent, vector<vector<vector<int>>> &adj,
             vector<bool> &visited, vector<int> &path, vector<int> &weights, int currWeight)
    {

        visited[u] = true;
        path.push_back(u);

        for (auto &edge : adj[u])
        {

            int v = edge[0];
            int w = edge[1];
            // avoid going back to the parent
            if (v == parent)
                continue;

            if (!visited[v])
            {

                weights.push_back(w);
                dfs(v, u, adj, visited, path, weights, currWeight + w);
                weights.pop_back();
            }
            else
            {

                // Found a cycle
                auto it = find(path.begin(), path.end(), v);
                if (it != path.end())
                {

                    int cycleWeight = 0;
                    int idx = it - path.begin();
                    for (int i = idx; i < weights.size(); i++)
                    {

                        cycleWeight += weights[i];
                    }
                    // add the closing edge
                    cycleWeight += w;
                    minCycle = min(minCycle, cycleWeight);
                }
            }
        }

        path.pop_back();
        visited[u] = false;
    }
    int shortestPath(int V, vector<vector<vector<int>>> &adj, int src, int dest)
    {

        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        // priority queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            pair<int, int> top = pq.top();
            pq.pop();
            int d = top.first, u = top.second;

            if (d > dist[u])
                continue;

            for (auto &neighbor : adj[u])
            {
                int v = neighbor[0];
                int w = neighbor[1];

                // Skip the ignored edge
                if ((u == src && v == dest) || (u == dest && v == src))
                    continue;

                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[dest];
    }
    int findMinCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<vector<int>>> adj = constructadj(V, edges);
        int minCycle = INT_MAX;

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            int dist = shortestPath(V, adj, u, v);

            if (dist != INT_MAX)
            {
                minCycle = min(minCycle, dist + w);
            }
        }

        return minCycle;
    }
};
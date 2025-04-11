//Dijkstra Algorithm
class Solution {
    public:
    vector<vector<vector<int>>> constructAdj(vector<vector<int>> &edges, int V){

        // adj[u] = list of {v, wt}
        vector<vector<vector<int>>> adj(V);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        return adj;
    }

    // Returns shortest distances from src to all other vertices
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<vector<int>>> adj = constructAdj(edges, V);

        // Set to store {distance, node}
        set<pair<int, int>> st;

        // Distance vector initialized to INF
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty()) {
            auto it = *(st.begin());
            int u = it.second;

            // Remove the node with the smallest distance
            st.erase(it);

            for (auto x : adj[u]) {
                int v = x[0];
                int weight = x[1];

                // If shorter path found
                if (dist[v] > dist[u] + weight) {

                    // If v already in set, erase the older (larger dist) entry
                    if (dist[v] != INT_MAX) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = dist[u] + weight;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
    };
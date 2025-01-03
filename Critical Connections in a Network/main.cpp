class Solution {
    private:
        vector<vector<int>> ans;
        vector<vector<int>> adj;
        vector<bool> vis;

        vector<int> time;
        vector<int> low;
        int timer = 1;

        void dfs(int node, int parent) {
            vis[node] = true;

            time[node] = timer;
            low[node] = timer;

            timer++;

            for(auto i : adj[node]) {
                if(i == parent) continue;
                if(!vis[i]) {
                    dfs(i, node);
                    low[node] = min(low[node], low[i]);

                    if(low[i] > time[node]) {
                        ans.push_back({node, i});
                    }

                } else {
                    low[node] = min(low[node], low[i]);
                }
            }
        }

    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            adj.resize(n);

            for(auto i : connections) {
                adj[i[0]].push_back(i[1]);
                adj[i[1]].push_back(i[0]);
            }

            vis.resize(n, false);
            time.resize(n, INT_MAX);
            low.resize(n, INT_MAX);

            dfs(0, -1);

            return ans;
        }
};
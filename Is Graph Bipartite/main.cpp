class Solution {
    public:
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();

            vector<bool> vis(n, false);
            vector<int> col(n, -1);

            queue<pair<int, int>> q; // {node, colour}
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    q.push({i, 0});
                    vis[i] = true;
                    col[i] = 0;

                    while(!q.empty()) {
                        pair<int, int> p = q.front();
                        q.pop();

                        int node = p.first;
                        int colour = p.second;

                        for(int& it : graph[node]) {
                            if(!vis[it]) {
                                vis[it] = true;
                                col[it] = !colour;
                                q.push({it, !colour});
                            } else {
                                if(col[it] == colour) return false;
                            }
                        }
                    }
                }
            }
            return true;
        }
};
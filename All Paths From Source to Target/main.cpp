class Solution {
    public:
        vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& adj) {
            int n = adj.size();

            queue<pair<int, vector<int>>> q;
            vector<vector<int>> ans;
            q.push({0, {0}});

            while(!q.empty()) {
                pair<int, vector<int>> p = q.front();
                q.pop();

                int node = p.first;
                vector<int> path = p.second;

                if(node == n - 1) {
                    ans.push_back(path);
                    continue;
                }

                for(auto i : adj[node]) {
                    if(find(begin(path), end(path), i) == path.end()) {
                        path.push_back(i);
                        q.push({i, path});
                        path.pop_back();
                    }
                }
            }

            return ans;
        }
};
class Solution {
private:
    vector<vector<int>> adj;
    int n;
    string colors;
    vector<bool> vis;
    vector<vector<int>> count;
    int maxi = INT_MIN;

    bool cycle() {
        vector<int> indegree(n,0);
        vector<int> res;

        for(int i = 0;i<n;i++) {
            for(int& node: adj[i]) {
                indegree[node]++;
            }
        }

        queue<int> q;

        for(int i = 0;i<n;i++) if(indegree[i] == 0) q.push(i);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);

            for(int& it: adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }

        }
        return res.size() != n;
    }


    int dfs(int node,vector<vector<int>>& count) {
        
        if(vis[node]) return 0;
        
        vis[node] = true;
        count[node][colors[node]-'a'] = 1;


        for(int& nei: adj[node]) {
            dfs(nei,count);
            for(int i = 0;i<26;i++) {
                count[node][i] = max(count[node][i],count[nei][i] + (i == (colors[node]-'a') ? 1 : 0));
            }
        }

        return *max_element(count[node].begin(),count[node].end());
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        n = colors.size();
        adj.resize(n);
        vis.resize(n,false);
        count.resize(n,vector<int>(26,0));

        for(vector<int>& edge:edges) adj[edge[0]].push_back(edge[1]);

        this->colors = colors;

        if(cycle()) return -1;


        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                maxi = max(dfs(i,count),maxi);
            }
        }
        return maxi;
    }
};
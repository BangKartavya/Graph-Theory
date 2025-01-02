class Solution {
private:
    int n;
    vector<vector<int>> isConnected;
    vector<bool> vis;
    
    void dfs(int node) {
        vis[node] = true;

        for(int i = 0;i<n;i++) {
            if(!vis[i] && isConnected[node][i]) dfs(i);   
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        this->isConnected = isConnected;
        vis.resize(n,false);
        int cnt = 0;

        for(int i = 0;i<n;i++) {
            if(!vis[i]) {
                dfs(i);
                cnt++;
            }
        }

        return cnt;
    }
};
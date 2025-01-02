class Solution {
    public:
        int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
            vector<vector<int>> adj(n);

            for(int i = 0; i < n; i++) {
                if(i == headID) continue;
                adj[manager[i]].push_back(i);
            }

            int currTime = 0;

            queue<vector<int>> q; // {node, internalTime}
            q.push({headID, 0});

            while(!q.empty()) {
                vector<int> p = q.front();
                q.pop();

                int node = p[0];
                int internalTime = p[1];

                currTime = max(currTime, internalTime);

                int reqTime = informTime[node];

                for(auto i : adj[node]) {
                    q.push({i, internalTime + reqTime});
                }
            }

            return currTime;
        }
};
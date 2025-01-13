class Solution {
    private:
        bool cycleCheck(vector<vector<int>>& adj, vector<int>& indegree, vector<int>& res) {
            queue<int> q; // {node}
            int n = adj.size();

            for(int i = 0; i < n; i++) {
                if(indegree[i] == 0) q.push(i);
            }

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                res.push_back(node);

                for(int& it : adj[node]) {
                    indegree[it]--;
                    if(indegree[it] == 0) q.push(it);
                }
            }

            return res.size() == n;
        }

    public:
        vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItem) {
            int k = m;

            for(int& it : group) {
                if(it == -1) it = k++;
            }

            vector<vector<int>> itemAdj(n);
            vector<vector<int>> groupAdj(k);
            vector<int> itemDegree(n);
            vector<int> groupDegree(k);

            for(int i = 0; i < n; i++) {
                if(!beforeItem[i].empty()) {
                    for(int& it : beforeItem[i]) {
                        itemAdj[it].push_back(i);
                        itemDegree[i]++;
                        if(group[it] != group[i]) {
                            groupAdj[group[it]].push_back(group[i]);
                            groupDegree[group[i]]++;
                        }
                    }
                }
            }

            vector<int> items;
            vector<int> grps;

            int topoItem = cycleCheck(itemAdj, itemDegree, items);
            int topoGroup = cycleCheck(groupAdj, groupDegree, grps);

            if(!topoItem || !topoGroup) return {};

            unordered_map<int, vector<int>> mp;

            for(int& it : items) {
                mp[group[it]].push_back(it);
            }

            vector<int> ans;

            for(int& grp : grps) {
                vector<int> temp = mp[grp];
                for(int& i : temp)
                    ans.push_back(i);
            }

            return ans;
        }
};
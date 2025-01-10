class DisjointSet {
    private:
        std::vector<int> rank;
        std::vector<int> parent;
        std::vector<int> size;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            size.resize(n + 1);
            parent.resize(n + 1);

            for(int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node) {
            if(node == parent[node]) return node;

            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ultimateParentOfu = findUltimateParent(u);
            int ultimateParentOfv = findUltimateParent(v);

            if(ultimateParentOfu == ultimateParentOfv) return;

            int rankOfu = rank[ultimateParentOfu];
            int rankOfv = rank[ultimateParentOfv];

            if(rankOfu < rankOfv) {
                parent[ultimateParentOfu] = ultimateParentOfv;
            } else if(rankOfv < rankOfu) {
                parent[ultimateParentOfv] = ultimateParentOfu;
            } else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                rank[ultimateParentOfu]++;
            }
        }

        void unionBySize(int u, int v) {
            int ultimateParentOfu = findUltimateParent(u);
            int ultimateParentOfv = findUltimateParent(v);

            if(ultimateParentOfu == ultimateParentOfv) return;

            int sizeOfu = size[ultimateParentOfu];
            int sizeOfv = size[ultimateParentOfv];

            if(sizeOfu <= sizeOfv) {
                parent[ultimateParentOfu] = ultimateParentOfv;
                size[ultimateParentOfv] += size[ultimateParentOfu];
            } else {
                parent[ultimateParentOfv] = ultimateParentOfu;
                size[ultimateParentOfu] += size[ultimateParentOfv];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string,int> mp;

        DisjointSet ds(n);

        for(int i = 0;i<n;i++) {
            int m = accounts[i].size();
            for(int j = 1;j<m;j++) {
                if(mp.find(accounts[i][j]) != mp.end()) {
                    ds.unionByRank(mp[accounts[i][j]],i);
                }
                else {
                    mp[accounts[i][j]] = i;
                }
            }
        }

        vector<vector<string>> temp(n);

        for(auto it: mp) {

            string mail = it.first;
            int node = it.second;

            int ultimateParent = ds.findUltimateParent(node);

            if(temp[ultimateParent].empty()) {
                temp[ultimateParent].push_back(accounts[ultimateParent][0]);
            }

            temp[ultimateParent].push_back(mail);

        }

        vector<vector<string>> result;

        for(vector<string>& t: temp) if(!t.empty()) result.push_back(t);

        return result;
        
    }
};
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
    private:
        bool similar(string s1, string s2) {
            if(s1 == s2) return true;

            int n = s1.size();

            vector<int> freq;

            for(int i = 0; i < n; i++) {
                if(s1[i] != s2[i]) {
                    freq.push_back(i);
                }

                if(freq.size() > 2) return false;
            }

            return freq.size() == 0 || (s1[freq[0]] == s2[freq[1]] && s1[freq[1]] == s2[freq[0]]);
        }

    public:
        int numSimilarGroups(vector<string>& strs) {
            int n = strs.size();
            DisjointSet ds(n);

            unordered_set<int> s;

            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    bool isSimilar = similar(strs[i], strs[j]);
                    if(isSimilar) {
                        ds.unionByRank(i, j);
                    }
                }
            }

            for(int i = 0; i < n; i++) {
                s.insert(ds.findUltimateParent(i));
            }

            return s.size();
        }
};
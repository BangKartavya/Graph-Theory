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

bool cmp(string s1,string s2) {
    string op1 = s1.substr(1,2);
    string op2 = s2.substr(1,2);
    

    if(op1 == "==" && op2 == "!=") return true;
    if(op2 == "==" && op1 == "!=") return false;
    else return false;


}

class Solution {
public:
    bool equationsPossible(vector<string> equations) {
        DisjointSet ds(26);

        sort(begin(equations),end(equations),cmp);

        for(string& equation: equations) {
            char var1 = equation[0];
           
            string operation;

            operation+=equation[1];
            operation+="=";

            char var2 = equation[3];

            if(operation == "==") {
                ds.unionByRank(var1-'a',var2-'a');
            }
            else {
                int ultimateParentOfvar1 = ds.findUltimateParent(var1-'a');
                int ultimateParentOfvar2 = ds.findUltimateParent(var2-'a');

                if(ultimateParentOfvar1 == ultimateParentOfvar2) return false;
            }
        }
        return true;
    }
};
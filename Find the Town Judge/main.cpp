class Solution {
    public:
        int findJudge(int n, vector<vector<int>>& trust) {
            vector<vector<int>> adj(n + 1);

            for(vector<int>& trustPeople : trust) {
                adj[trustPeople[0]].push_back(trustPeople[1]);
            }

            vector<int> potentialJudges;

            for(int i = 1; i <= n; i++) {
                if(adj[i].empty()) potentialJudges.push_back(i);
            }

            for(int judge : potentialJudges) {
                bool found = true;
                for(int i = 1; i <= n; i++) {
                    if(i == judge) continue;

                    if(find(begin(adj[i]), end(adj[i]), judge) == adj[i].end()) {
                        found = false;
                        break;
                    }
                }
                if(found) return judge;
            }

            return -1;
        }
};
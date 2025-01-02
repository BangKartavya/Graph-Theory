class Solution {
    public:
        vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
            vector<vector<int>> redAdj(n);
            vector<vector<int>> blueAdj(n);

            for(auto i : redEdges)
                redAdj[i[0]].push_back(i[1]);
            for(auto i : blueEdges)
                blueAdj[i[0]].push_back(i[1]);

            vector<int> redVis(n, false);
            vector<int> blueVis(n, false);

            vector<int> ans(n, -1);

            queue<vector<int>> q; // {node, dist, edge}
            q.push({0, 0, -1});

            while(!q.empty()) {
                vector<int> v = q.front();
                q.pop();

                int node = v[0];
                int dis = v[1];
                int edge = v[2];

                cout << "node , dis , edge : " << node << " , " << dis << " , " << edge << endl;

                if(ans[node] == -1) ans[node] = dis;

                if(edge != 1) {
                    // (current blue, visit red)
                    for(auto i : redAdj[node]) {
                        if(!redVis[i]) {
                            redVis[i] = true;
                            q.push({i, dis + 1, 1});
                        }
                    }
                }

                if(edge != 0) {
                    // (current red, visit blue)
                    for(auto i : blueAdj[node]) {
                        if(!blueVis[i]) {
                            blueVis[i] = true;
                            q.push({i, dis + 1, 0});
                        }
                    }
                }
            }

            return ans;
        }
};
class Solution {
    private:
        int dirX[4] = {0, 1, 0, -1};
        int dirY[4] = {1, 0, -1, 0};

        vector<vector<int>> mat;
        vector<vector<int>> ans;
        vector<vector<bool>> vis;
        queue<vector<int>> q; // {x,y,steps}

        int n;
        int m;

        void bfs() {
            while(!q.empty()) {
                vector<int> v = q.front();
                q.pop();

                int x = v[0];
                int y = v[1];
                int steps = v[2];

                if(mat[x][y] == 1) {
                    if(ans[x][y] > steps)
                        ans[x][y] = steps;
                }

                for(int i = 0; i < 4; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if(newX < 0 || newX >= m || newY < 0 || newY >= n) {
                        continue;
                    }
                    if(!vis[newX][newY]) {
                        vis[newX][newY] = true;
                        q.push({newX, newY, steps + 1});
                    }
                }
            }
        }

    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            m = mat.size();
            n = mat[0].size();
            this->mat = mat;
            ans.resize(m, vector<int>(n, INT_MAX));

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] == 0) {
                        ans[i][j] = 0;
                        q.push({i, j, 0});
                    }
                }
            }

            vis.resize(m, vector<bool>(n, false));
            bfs();

            return ans;
        }
};
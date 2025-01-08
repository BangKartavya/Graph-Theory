class Solution {
    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector<bool>> vis(m, vector<bool>(n, false));

            int dirX[4] = {0, -1, 0, 1};
            int dirY[4] = {1, 0, -1, 0};

            int ans = 0;
            queue<pair<int, int>> q;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 1 && !vis[i][j]) {
                        q.push({i, j});
                        int currCount = 1;
                        vis[i][j] = true;

                        while(!q.empty()) {
                            pair<int, int> p = q.front();
                            q.pop();

                            int x = p.first;
                            int y = p.second;

                            for(int k = 0; k < 4; k++) {
                                int newX = x + dirX[k];
                                int newY = y + dirY[k];

                                if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                                if(grid[newX][newY] == 1 && !vis[newX][newY]) {
                                    q.push({newX, newY});
                                    vis[newX][newY] = true;
                                    currCount++;
                                }
                            }
                        }
                        ans = max(ans, currCount);
                    }
                }
            }

            return ans;
        }
};
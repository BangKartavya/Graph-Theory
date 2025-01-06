class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            if(grid[0][0] == 1) return -1;

            int n = grid.size();
            vector<vector<bool>> vis(n, vector<bool>(n, false));

            int dirX[8] = {1, 1, 0, -1, -1, -1, 0, 1};
            int dirY[8] = {0, 1, 1, 1, 0, -1, -1, -1};

            queue<vector<int>> q; // {x,y,steps}
            q.push({0, 0, 1});
            vis[0][0] = true;

            while(!q.empty()) {
                vector<int> v = q.front();
                q.pop();

                int x = v[0];
                int y = v[1];
                int steps = v[2];

                if(x == n - 1 && y == n - 1) return steps;

                for(int i = 0; i < 8; i++) {
                    int newX = x + dirX[i];
                    int newY = y + dirY[i];

                    if(newX < 0 || newX >= n || newY < 0 || newY >= n) continue;

                    if(!vis[newX][newY] && grid[newX][newY] == 0) {
                        vis[newX][newY] = true;
                        q.push({newX, newY, steps + 1});
                    }
                }
            }

            return -1;
        }
};
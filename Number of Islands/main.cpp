class Solution {
private:
    int m;
    int n;

    vector<vector<char>> grid;
    vector<vector<bool>> vis;

    int dirX[4] = {1,0,-1,0};
    int dirY[4] = {0,1,0,-1};


    void dfs(int x,int y) {
        vis[x][y] = true;

        for(int i = 0;i<4;i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

            if(!vis[newX][newY] && grid[newX][newY] == '1') {
                dfs(newX,newY);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        this->grid = grid;
        vis.resize(m,vector<bool>(n,false));

        int cnt = 0;

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    dfs(i,j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
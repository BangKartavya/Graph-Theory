class Solution {
private:
    queue<vector<int>> q2; // {x,y}
    int n;
    vector<vector<int>> grid;

    int dirX[4] = {0,1,0,-1};
    int dirY[4] = {1,0,-1,0};
    
    void dfs(int x,int y) {
        q2.push({x,y});
        grid[x][y] = 2;

        for(int i = 0;i<4;i++) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];

            if(newX < 0 || newX >= n || newY < 0 || newY >= n) continue;

            if(grid[newX][newY] == 1) {
                dfs(newX,newY);
            }
        }

    }
public:
    int shortestBridge(vector<vector<int>>& g) {
        this->grid = g;
        n = grid.size();
        int x;
        int y;

        for(int i = 0;i<n;i++) {
            bool found = false;
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1) {
                    found = true;
                    x = i;
                    y = j;
                    break;
                }
            }
            if(found) break;
        }

        dfs(x,y);
        int flips = 0;
        while(!q2.empty()) {
            int siz = q2.size();
            cout << "siz : " << siz << endl;
            while(siz--) {

                vector<int> v = q2.front();
                q2.pop();

                int X = v[0];
                int Y = v[1];

                for(int i = 0;i<4;i++) {
                    int newX = X + dirX[i];
                    int newY = Y + dirY[i];

                    if(newX < 0 || newX >= n || newY < 0 || newY >= n) continue;

                    if(grid[newX][newY] == 1) {
                        return flips;
                    }
                    else if(grid[newX][newY] == 0) {
                        grid[newX][newY] = 2;
                        q2.push({newX,newY});
                    }

                }
            }
            flips++;
        }
        return 0;
    }
};
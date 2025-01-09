class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visPacific(m,vector<bool>(n,false));
        vector<vector<bool>> visAtlantic(m,vector<bool>(n,false));

        int dirX[4] = {0,-1,0,1};
        int dirY[4] = {1,0,-1,0};

        queue<pair<int,int>> q;

        for(int j = 0;j<n;j++) {
            visPacific[0][j] = true;
            q.push({0,j});
        }

        for(int i = 1;i<m;i++) {
            visPacific[i][0] = true;
            q.push({i,0});
        }

        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;

            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;


                if(heights[newX][newY] >= heights[x][y] && !visPacific[newX][newY]) {
                    q.push({newX,newY});
                    visPacific[newX][newY] = true;
                }

            }
        }

        for(int j = 0;j<n;j++) {
            visAtlantic[m-1][j] = true;
            q.push({m-1,j});
        }

        for(int i = 0;i<m-1;i++) {
            visAtlantic[i][n-1] = true;
            q.push({i,n-1});
        }

        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();

            int x = p.first;
            int y = p.second;

            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;


                if(heights[newX][newY] >= heights[x][y] && !visAtlantic[newX][newY]) {
                    q.push({newX,newY});
                    visAtlantic[newX][newY] = true;
                }

            }
        }



        vector<vector<int>> result;
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(visPacific[i][j] && visAtlantic[i][j]) result.push_back({i,j});
            }
        }

        return result;

    }
};
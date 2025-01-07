class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dirX[4] = {0,-1,0,1};
        int dirY[4] = {1,0,-1,0};

        int keyCnt = 0;
        queue<vector<int>> q; // {x,y,steps,*keys}
        unordered_set<string> s;

        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == '@') {
                    q.push({i,j,0,0});
                    s.insert(to_string(i) + " " + to_string(j) + " 0");
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') keyCnt++;
            }
        }

        while(!q.empty()) {
            vector<int> v = q.front();
            q.pop();

            int x = v[0];
            int y = v[1];
            int steps = v[2];
            int keys = v[3];

            if(keys == (1 << keyCnt) - 1) return steps;

            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];


                if(newX < 0 || newX >= m || newY < 0 || newY >= n) continue;

                if(grid[newX][newY] == '#') continue;

                
                if(s.find(to_string(newX) + " " + to_string(newY) + " " + to_string(keys)) == s.end()) {
                    s.insert(to_string(newX) + " " + to_string(newY) + " " + to_string(keys));
                    if(grid[newX][newY] >= 'A' && grid[newX][newY] <= 'Z') {
                        if((1 << (grid[newX][newY] - 'A')) & keys) {
                            q.push({newX,newY,steps+1,keys});
                        }
                        else {
                            continue;
                        }
                    }
                    else if(grid[newX][newY] >= 'a' && grid[newX][newY] <= 'z') {
                        q.push({newX,newY,steps+1,keys | (1 << (grid[newX][newY] - 'a'))});
                        
                    }

                    else {
                        q.push({newX,newY,steps+1,keys});
                    }
                }

            }

        }

        return -1;

    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& adj, vector<int>& entrance) {
        int m = adj.size();
        int n = adj[0].size();

        int dirX[4] = {1,0,-1,0};
        int dirY[4] = {0,1,0,-1}; 

        vector<vector<bool>> vis(m,vector<bool>(n,false));

        queue<vector<int>> q;
        q.push({entrance[0],entrance[1],0}); // {x,y,steps}
        vis[entrance[0]][entrance[1]] = true;

        while(!q.empty()) {
            vector<int> p = q.front();
            q.pop();

            int x = p[0];
            int y = p[1];
            int steps = p[2];

            if(x == 0 || x == m-1 || y == 0 || y == n-1) {
                if(!(x == entrance[0] && y == entrance[1])) return steps; 
            }

            for(int i = 0;i<4;i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if(newX < 0 || newX >= m || newY < 0 || newY >= n || (adj[newX][newY] == '+')) continue;

                if(!vis[newX][newY]) {
                    vis[newX][newY] = true;
                    q.push({newX,newY,steps+1});
                }

            }

        }

        return -1;

    }
};
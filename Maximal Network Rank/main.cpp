class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<vector<int>> adjMax(n,vector<int>(n+1,0));

        for(vector<int>& road: roads) {
            adjMax[road[0]][road[1]] = 1;
            adjMax[road[1]][road[0]] = 1;
        }   

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                adjMax[i][n]+=(adjMax[i][j]);
            }
        }

        int result = 0;

        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i == j) continue;

                int totalRoads = adjMax[i][n] + adjMax[j][n];
                
                if(adjMax[i][j]) totalRoads--;

                result = max(result,totalRoads);
            }
        }

        return result;
    }
};
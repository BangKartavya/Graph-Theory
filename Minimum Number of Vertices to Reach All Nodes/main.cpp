class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n,0);

        for(vector<int>& edge : edges) {
            inDegree[edge[1]]++;
        }

        vector<int> res;

        for(int i = 0;i<n;i++) if(inDegree[i] == 0) res.push_back(i);


        return res;


    }
};
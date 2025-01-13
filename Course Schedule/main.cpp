class Solution {
    private:
        vector<bool> vis;
        vector<vector<int>> adj;

    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            adj.resize(numCourses);
            vis.resize(numCourses, false);

            for(vector<int>& prerequisite : prerequisites) {
                adj[prerequisite[1]].push_back(prerequisite[0]);
            }
            queue<int> q; // {node}

            vector<int> indegree(numCourses, 0);

            for(int i = 0; i < numCourses; i++) {
                for(int& node : adj[i])
                    indegree[node]++;
            }

            for(int i = 0; i < numCourses; i++) {
                if(indegree[i] == 0) q.push(i);
            }
            int visited = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();
                visited++;

                for(int& it : adj[node]) {
                    indegree[it]--;

                    if(indegree[it] == 0) q.push(it);
                }
            }

            return visited == numCourses;
        }
};
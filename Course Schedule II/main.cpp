class Solution {
private:

    vector<vector<int>> adj;
    int numCourses;
    vector<vector<int>> prerequisites;
    stack<int> stk;
    vector<bool> vis;

    bool canFinish() {
        adj.resize(numCourses);
        for(vector<int>& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }
        queue<int> q; // {node}

        vector<int> indegree(numCourses,0);

        for(int i = 0;i<numCourses;i++) {
            for(int& node: adj[i]) indegree[node]++;
        }

        for(int i = 0;i<numCourses;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        int visited = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            for(int& it: adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) q.push(it);
            }

        }

        return visited == numCourses;
    }

    void dfs(int node) {
        vis[node] = true;

        for(int& it: adj[node]) {
            if(!vis[it]) {
                dfs(it);
            }
        }

        stk.push(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        this->numCourses = numCourses,
        this->prerequisites = prerequisites;
        vis.resize(numCourses,false);

        if(!canFinish()) return {};

        for(int i = 0;i<numCourses;i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        vector<int> res;

        while(!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;


    }
};
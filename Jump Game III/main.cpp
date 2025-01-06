class Solution {
    public:
        bool canReach(vector<int>& arr, int start) {
            unordered_set<int> idx;
            int n = arr.size();

            for(int i = 0; i < n; i++) {
                if(arr[i] == 0) {
                    idx.insert(i);
                }
            }

            if(idx.empty()) return false;

            vector<bool> vis(n, false);
            queue<int> q;
            q.push(start);
            vis[start] = true;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                if(idx.find(curr) != idx.end()) return true;

                int new1 = curr + arr[curr];
                int new2 = curr - arr[curr];

                if(new1 >= 0 && new1 < n && !vis[new1]) {
                    q.push(new1);
                    vis[new1] = true;
                }

                if(new2 >= 0 && new2 < n && !vis[new2]) {
                    q.push(new2);
                    vis[new2] = true;
                }
            }

            return false;
        }
};
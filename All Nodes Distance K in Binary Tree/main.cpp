/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
        vector<vector<int>> adj;

        void inOrder(TreeNode* root) {
            if(!root) return;

            if(root->left) {
                inOrder(root->left);
                adj[root->val].push_back(root->left->val);
                adj[root->left->val].push_back(root->val);
            }

            if(root->right) {
                adj[root->val].push_back(root->right->val);
                adj[root->right->val].push_back(root->val);
                inOrder(root->right);
            }
        }

    public:
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            TreeNode* temp = root;
            adj.resize(505);
            inOrder(temp);

            vector<int> ans;
            vector<int> vis(505, false);

            queue<pair<int, int>> q; // {node, dist}
            q.push({target->val, 0});
            vis[target->val] = true;

            while(!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();

                int node = p.first;
                int dist = p.second;

                if(dist == k) {
                    ans.push_back(node);
                    continue;
                }

                for(auto i : adj[node]) {
                    if(!vis[i]) {
                        vis[i] = true;
                        q.push({i, dist + 1});
                    }
                }
            }
            return ans;
        }
};
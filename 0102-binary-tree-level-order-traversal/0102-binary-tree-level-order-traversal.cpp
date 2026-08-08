/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     void solve(vector<vector<int>>& ans , queue<TreeNode*>& q){
        if(q.empty()) return ;
        vector<int>an ;
        queue<TreeNode*> qe;
        while(!q.empty()){
            an.push_back(q.front()->val);
            if(q.front()->left) qe.push(q.front()->left);
            if(q.front()->right) qe.push(q.front()->right);
            q.pop();
        }
        ans.push_back(an);
        solve(ans , qe );
     }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        queue<TreeNode*> q;
        if(root == NULL) return ans ;
        q.push(root);
        solve(ans , q);
        return ans;
    }
};
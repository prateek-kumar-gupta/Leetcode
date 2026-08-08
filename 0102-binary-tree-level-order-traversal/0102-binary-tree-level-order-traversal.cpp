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
        if(q.empty()||q.front()==NULL) return ;
        vector<int>an ;
        while(!q.empty()){
            if(q.front() == NULL){q.pop(); break ;}
            an.push_back(q.front()->val);
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        q.push(NULL);
        ans.push_back(an);
        solve(ans , q );
     }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        queue<TreeNode*> q;
        if(root == NULL) return ans ;
        q.push(root);
        q.push(NULL);
        solve(ans , q);
        return ans;
    }
};
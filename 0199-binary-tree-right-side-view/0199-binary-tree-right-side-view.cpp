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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ;
        queue<pair<TreeNode* , int >>q;
        TreeNode* node = root ;
        int h = 0;
        map<int , int >mp;
        if(root == NULL) return ans ;
        q.push({root,0});
        while(!q.empty()){
          node = q.front().first;
          h = q.front().second;
          if(h<ans.size()){ans[h] = node->val;}
          else ans.push_back(node->val);
          q.pop();
          if(node->left)q.push({node->left , h + 1});
          if(node->right)q.push({node->right, h + 1});

          
        }
        
        return ans ;
    }
};
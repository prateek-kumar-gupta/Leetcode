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
    void inorder(TreeNode* root , vector<int>&ar){
if(root == NULL) return ;
if(root->left) inorder(root->left,ar);
ar.push_back(root->val);
if(root->right) inorder(root->right,ar);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ar;
        inorder(root , ar);
        return ar[k-1];
    }
};
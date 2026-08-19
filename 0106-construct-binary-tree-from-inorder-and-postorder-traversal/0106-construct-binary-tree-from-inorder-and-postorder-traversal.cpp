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
      TreeNode* solve(vector<int>& postorder, int& pi,
                    int inLeft, int inRight,
                    unordered_map<int, int>& pos) {

        if(inLeft > inRight)
            return NULL;

        int value = postorder[pi--];
        TreeNode* root = new TreeNode(value);

        int mid = pos[value];

        root->right = solve(postorder, pi,
                            mid + 1, inRight, pos);
        root->left = solve(postorder, pi,
                           inLeft, mid - 1, pos);


        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> pos;

        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        int pi = postorder.size() - 1;

        return solve(postorder, pi, 0, inorder.size() - 1, pos);
                     
    }
};

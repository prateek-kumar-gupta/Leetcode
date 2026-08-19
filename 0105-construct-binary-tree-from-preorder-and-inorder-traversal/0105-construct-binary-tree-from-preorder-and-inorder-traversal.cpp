// class Solution {
// public:
//     void solve(TreeNode* root, vector<int> left, vector<int> right,
//                vector<int>& preorder) {

//         if(preorder.empty()) {
//             root->left = NULL;
//             root->right = NULL;
//             return;
//         }

//         int val = preorder[0];
//         preorder.erase(preorder.begin());

//         int ind = -1;

//         for(int i = 0; i < left.size(); i++) {
//             if(left[i] == val) {
//                 ind = i;
//                 break;
//             }
//         }

//         if(ind != -1) {
//             TreeNode* node = new TreeNode(val);
//             root->left = node;

//             vector<int> l, r;

//             for(int i = 0; i < left.size(); i++) {
//                 if(i < ind)
//                     l.push_back(left[i]);
//                 else if(i > ind)
//                     r.push_back(left[i]);
//             }

//             solve(node, l, r, preorder);
//         }
//         else {
//             root->left = NULL;
//         }

//         ind = -1;

//         for(int i = 0; i < right.size(); i++) {
//             if(right[i] == val) {
//                 ind = i;
//                 break;
//             }
//         }

//         if(ind != -1) {
//             TreeNode* node = new TreeNode(val);
//             root->right = node;

//             vector<int> l, r;

//             for(int i = 0; i < right.size(); i++) {
//                 if(i < ind)
//                     l.push_back(right[i]);
//                 else if(i > ind)
//                     r.push_back(right[i]);
//             }

//             solve(node, l, r, preorder);
//         }
//         else {
//             root->right = NULL;
//         }
//     }

//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

//         if(preorder.empty())
//             return NULL;

//         TreeNode* root = new TreeNode(preorder[0]);
//         preorder.erase(preorder.begin());

//         int ind = 0;

//         for(int i = 0; i < inorder.size(); i++) {
//             if(inorder[i] == root->val) {
//                 ind = i;
//                 break;
//             }
//         }

//         vector<int> left, right;

//         for(int i = 0; i < inorder.size(); i++) {
//             if(i < ind)
//                 left.push_back(inorder[i]);
//             else if(i > ind)
//                 right.push_back(inorder[i]);
//         }

//         solve(root, left, right, preorder);

//         return root;
//     }
// };
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, int& preIndex,
                    int inLeft, int inRight,
                    unordered_map<int, int>& pos) {

        if(inLeft > inRight)
            return NULL;

        int value = preorder[preIndex++];
        TreeNode* root = new TreeNode(value);

        int mid = pos[value];

        root->left = solve(preorder, preIndex,
                           inLeft, mid - 1, pos);

        root->right = solve(preorder, preIndex,
                            mid + 1, inRight, pos);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> pos;

        for(int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        int preIndex = 0;

        return solve(preorder, preIndex,
                     0, inorder.size() - 1, pos);
    }
};
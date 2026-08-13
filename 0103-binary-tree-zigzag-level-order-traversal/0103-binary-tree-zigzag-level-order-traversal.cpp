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
// class Solution {
// public:
//     void solve(queue<TreeNode*>q , vector<vector<int>>& ans , int a ){
//     if(q.empty()) return ;
//     queue<TreeNode*>qn;
//     vector<int>an;
//     while(!q.empty()){
//       an.push_back(q.front()->val);
//       if(q.front()->left) qn.push(q.front()->left);
//       if(q.front()->right) qn.push(q.front()->right);
//       q.pop();
//     }
//     if(a!=0){ reverse(an.begin(), an.end());ans.push_back(an); solve(qn , ans , 0);}
//     else { ans.push_back(an); solve(qn , ans , 1);}
// }
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans ;
//         queue<TreeNode*> q ;
//         if(root!=NULL)
//            q.push(root);
//            solve(q , ans , 0);
//            return ans ;
//     }
// };
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == NULL)
            return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        bool leftToRight = true;

        while(!nodesQueue.empty()) {

            int size = nodesQueue.size();

            vector<int> row(size);

            for(int i = 0; i < size; i++) {

                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = leftToRight ? i : (size - 1 - i);

                row[index] = node->val;

                if(node->left)
                    nodesQueue.push(node->left);

                if(node->right)
                    nodesQueue.push(node->right);
            }

            leftToRight = !leftToRight;

            result.push_back(row);
        }

        return result;
    }
};
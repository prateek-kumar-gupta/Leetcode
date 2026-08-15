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
public:
    bool find(TreeNode* root , TreeNode* a , vector<TreeNode*> &an){
       if(root==NULL) return false ;
       if(root == a) {an.push_back(a); return true;}
       an.push_back(root);
       if(find(root->left , a , an)) return true;
       if(find(root->right, a ,an)) return true;
       an.pop_back();
       return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>an1 ;
        vector<TreeNode*>an2 ;
        find(root , p , an1);
        find(root , q , an2);
        int n = min(an1.size(), an2.size());
        TreeNode* ans = NULL;
        for(int i = n-1 ; i >=0 ; i--){
              if(an1[i]==an2[i]){ans = an1[i]; break;}
        }
        return ans ;
    }
};
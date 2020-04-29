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
    int helper(TreeNode* root, int &maxsum){
        if(root==nullptr)
            return 0;
        int l=helper(root->left,maxsum);
        int r=helper(root->right,maxsum);
        maxsum=max(maxsum,l+r+root->val);
        return max(0,max(l+root->val,r+root->val));
        
    }
    int maxPathSum(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int maxsum=INT_MIN;
        helper(root,maxsum);
        return maxsum;
    }
};
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
     int maxdiadepth = 0;
    
    int dfs(TreeNode* root){        
        if(root == NULL) return 0;//leaf node
        
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        //calculate diameter for each node and maintain the maximum diameter and at last return maxdiameter
        if(leftdepth + rightdepth > maxdiadepth) maxdiadepth = leftdepth + rightdepth;
        return max(leftdepth,rightdepth)+1;     
    }
    
    int diameterOfBinaryTree(TreeNode* root) {        
        dfs(root);
        
        return maxdiadepth;
    }
};
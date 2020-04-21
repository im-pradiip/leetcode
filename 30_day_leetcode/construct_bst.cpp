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
    TreeNode* helper(vector<int>&preorder,int& index, int maximum){
        if(index>=preorder.size()||preorder[index]>maximum)
            return nullptr;
        int value=preorder[index];
        TreeNode* root= new TreeNode(value);
        
        index++;
        root->left=helper(preorder,index,value);
        root->right=helper(preorder,index,maximum);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(preorder,index,INT_MAX);
        
    }
};
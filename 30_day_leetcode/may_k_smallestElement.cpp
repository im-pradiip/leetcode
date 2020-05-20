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
    //approach 1
    int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*>stk;
        TreeNode* p = root;
        while(p||!stk.empty()){
            while(p){
                stk.push(p);
                p=p->left;
            }
            p=stk.top();
            if(--k==0)
                return p->val;
            stk.pop();
            p=p->right;
        }
        return 0;
    }
    //approach2
    /*
    void helper(TreeNode* root,vector<int>&res){
        if(root->left)
            helper(root->left,res);
        res.push_back(root->val);
        if(root->right)
            helper(root->right,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>res;
        helper(root,res);
        return res[k-1];
    }
    */
};
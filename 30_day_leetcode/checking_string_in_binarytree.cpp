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
    bool helper(TreeNode* root, vector<int>& arr,int pos){
        if(pos>=arr.size()) // handles the case when array finishes but root is not leaf node
            return false;  
        
        if(root==nullptr) // handles when root reaches last node ie leaf node
            return false;
        
        if(pos==arr.size()-1&&root->val==arr[pos]&&root->left==nullptr&&root->right==nullptr)
            return true;  //pos reaches last of array and val of root and arr[pos] is same and root is a leafnode
        cout<<root->val<<" "<<arr[pos]<<" ";
        if(root->val!=arr[pos]) // when in between node if the value is not same as array just return no need to check further
            return false;
        bool left=helper(root->left,arr,pos+1);
        bool right=helper(root->right,arr,pos+1);
        return left||right; // return true if one the case is true.....else false 
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
         return helper(root,arr,0);
    }
};
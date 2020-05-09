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
    pair<int,int>* dfs(TreeNode* root,int value,int depth=0,int parent=-1){
        pair<int,int>* p=new pair<int,int>; //pair consist of paent and depth
        if(root->val==value){
            
            p->first=depth; //if we found the value just make pair of parent and depth
            p->second=parent;
            return p;
        }
        if(root->left){
            p=dfs(root->left,value,depth+1,root->val);//traversev to left subtree
            if(p!=nullptr)//if we get p just return it
                return p;
        }
         if(root->right){
            p=dfs(root->right,value,depth+1,root->val);//traverse to right subtree
            if(p!=nullptr)//if we get p just return it
                return p;
        }
        return nullptr;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==nullptr)
            return false;
        pair<int,int>* check_x=dfs(root,x,0,-1);
        pair<int,int>* check_y=dfs(root,y,0,-1);
        if(!check_x||!check_y)//if one of them is nullptr means we dont get that value
            return false;
        //checking for same depth and not same parent
        if(check_x->first==check_y->first&&check_x->second!=check_y->second)
            return true;
        return false;
    }
};
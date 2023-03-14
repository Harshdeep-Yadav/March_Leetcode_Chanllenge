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
    void helper(TreeNode*node,vector<int>&ans,int num)
    {
        if(node!=NULL){
        
            if(node->left!=NULL){
               helper(node->left,ans,num*10+node->val);
            }
            if(node->right!=NULL)
            {
                helper(node->right,ans,num*10+node->val);        
            }  
            if(node->left==NULL&&node->right==NULL){ //leaf node
                ans.push_back(num*10+node->val);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        vector<int> ans;
        helper(root,ans,0);
        int res=0;
        for(auto it : ans)
        {
            res+=it;
        }
        return res;
    }
    
};

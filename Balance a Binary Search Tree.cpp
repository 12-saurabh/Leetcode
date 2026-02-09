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
    void createinorder(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return;
        }
        createinorder(root->left,v);
        v.push_back(root->val);
        createinorder(root->right,v);
    }
    TreeNode* createTree(vector<int>&v,int s,int e){
        if(s>e){
            return NULL;
        }

        int mid=(s+e)/2;

        TreeNode* node=new TreeNode(v[mid]);
        node->left=createTree(v,s,mid-1);
        node->right=createTree(v,mid+1,e);

        return node;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;

        createinorder(root,v);

        return createTree(v,0,v.size()-1);
        
    }
};

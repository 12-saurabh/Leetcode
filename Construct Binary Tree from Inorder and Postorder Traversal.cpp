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

    void createmapping(vector<int>&inorder,int size,map<int,int>&mp){
        for(int i=0;i<size;i++){
            int element=inorder[i];
            int index=i;
            mp[element]=index;
        }
    }

    TreeNode* createtree(map<int,int>&mp,vector<int>&inorder,int inorderstart,int inorderend,vector<int>&postorder,int &postorderindex,int size){

        if(postorderindex<0 || inorderstart>inorderend){
            return NULL;
        }


        int element=postorder[postorderindex];
        postorderindex--;

        TreeNode* root=new TreeNode(element);

        int position=mp[element];

        root->right=createtree(mp,inorder,position+1,inorderend,postorder,postorderindex,size);
        root->left=createtree(mp,inorder,inorderstart,position-1,postorder,postorderindex,size);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=postorder.size();

        int postorderindex=size-1;
        int inorderstart=0;
        int inorderend=size-1;

        map<int,int>mp;

        createmapping(inorder,size,mp);

        return createtree(mp,inorder,inorderstart,inorderend,postorder,postorderindex,size);




        
    }
};

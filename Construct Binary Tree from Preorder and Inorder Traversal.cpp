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

    // int searchelemenininorder(vector<int>&inorder,int &element,int size){
    //     for(int i=0;i<size;i++){
    //         if(inorder[i]==element){
    //             return i;
                
    //         }
    //     }

    //     return -1;

    // }


    void createmapping(vector<int>&inorder,int size,map<int,int>&mp){
        
        for(int i=0;i<size;i++){
            int element=inorder[i];
            int index=i;

            mp[element]=index;
        }

    }


    TreeNode* constructtree(map<int,int>&mp,vector<int>&preorder,int &preorderindex,vector<int>&inorder,int inorderstart,int inorderend,int size){

        if(preorderindex>=size || inorderstart>inorderend){
            return NULL;
        }

        int element=preorder[preorderindex];
        preorderindex++;

        TreeNode* root=new TreeNode(element);

        int position=mp[element];

        root->left=constructtree(mp,preorder,preorderindex,inorder,inorderstart,position-1,size);

        root->right=constructtree(mp,preorder,preorderindex,inorder,position+1,inorderend,size);

        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int size=preorder.size();
        int preorderindex=0;
        int inorderstart=0;
        int inorderend=size;

        map<int,int>mp;

        createmapping(inorder,size,mp);

        return constructtree(mp,preorder,preorderindex,inorder,inorderstart,inorderend,size);


        
    }
};

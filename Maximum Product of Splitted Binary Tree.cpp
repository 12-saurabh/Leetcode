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
    long long MOD=1e9+7;
    long long maxi=0;

    long long sum(TreeNode* node){
        if(!node){
            return 0;
        }

        node->val+=sum(node->left)+sum(node->right);
        return node->val;

    }
    int maxProduct(TreeNode* root) {
        if(root==NULL){
            return 0;
        }

        long long totalsum=sum(root);

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();

            if(!f){
                continue;
            }

            long long curr=(totalsum-(f->val))*(f->val);
            maxi=max(maxi,curr);

            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }

        return maxi%MOD;
        
    }
};

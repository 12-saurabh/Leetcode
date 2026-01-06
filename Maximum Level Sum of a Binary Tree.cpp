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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        
        int maxi=INT_MIN;
        int lev=0;
        int ans;

        while(!q.empty()){  
            int n=q.size();
            lev++;
            long currans=0;
            for(int i=1;i<=n;i++){
                TreeNode* front=q.front();
                q.pop();

                currans+=front->val;

                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }

            }

            if(currans>maxi){
                ans=lev;
                maxi=currans;
            }
        }

        return ans;
     
    }
};

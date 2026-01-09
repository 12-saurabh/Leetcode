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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }

        unordered_map<TreeNode*,TreeNode*>par;
        queue<TreeNode*>q;
        q.push(root);
        par[root]=NULL;

        vector<TreeNode*>last;

        while(!q.empty()){
            int size=q.size();
            last.clear();

            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                last.push_back(node);

                if(node->left){
                    par[node->left]=node;
                    q.push(node->left);
                }
                if(node->right){
                    par[node->right]=node;
                    q.push(node->right);
                }

            }
        }

        unordered_set<TreeNode*>deep(last.begin(),last.end());

        while(deep.size()>1){
            unordered_set<TreeNode*>next;
            for(auto node:deep){
                next.insert(par[node]);
            }

            deep=next;
        }
        return *deep.begin();
        
    }
};

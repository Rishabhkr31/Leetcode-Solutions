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
        int ans;
        int level=0;
        q.push(root);
         int maxi=INT_MIN;
        while(!q.empty()){
            int sum=0;
            int n=q.size();
            while(n--){
                TreeNode* m=q.front();
                sum+=m->val;

                q.pop();
                if(m->left!=NULL){
                    q.push(m->left);
                }
                if(m->right!=NULL){
                    q.push(m->right);
                }
            }
            level++;
            if(sum>maxi){
                ans=level;
                maxi=sum;


            }
    
        }

        return ans;
    }
};
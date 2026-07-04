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
    void solve(TreeNode* root,vector<double> &ans){
        if(!root) return;

        queue<TreeNode*> q;
        vector<int> temp;
        TreeNode* curr = root;
        q.push(curr);
        q.push(nullptr);

        while(!q.empty()){
            curr=q.front();
            q.pop();

            if(curr==nullptr){
                ans.push_back((accumulate(temp.begin(),temp.end(),0.0)/temp.size()));
                temp.clear();

                if(!q.empty()){
                    q.push(nullptr);
                }
                continue;
            }

            temp.push_back(curr->val);

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        solve(root,ans);

        return ans;
    }
};
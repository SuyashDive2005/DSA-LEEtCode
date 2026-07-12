/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void getpath(TreeNode* root,vector<int>&paths,vector<int>&p) {
        if (!root)
            return;

        p.push_back(root->val);
        int spth=0;
        if (!root->left && !root->right) {
            for(int i=0;i<p.size();i++){
                spth=spth*10+p[i];
            }
            paths.push_back(spth);
        }
        
        getpath(root->left, paths, p);
        getpath(root->right, paths, p);
        p.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<int> paths;
        vector<int>p;
        getpath(root, paths,p);

        int ans=accumulate(paths.begin(),paths.end(),0);
        return ans;
    }
};
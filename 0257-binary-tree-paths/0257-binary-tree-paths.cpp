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
    void solve(TreeNode* root,vector<string>& path,vector<int> &spth){
        if(!root) return;

        spth.push_back(root->val);
        string pth="";
        if(!root->left && !root->right){
            for(int i=0;i<spth.size()-1;i++){
                pth+=to_string(spth[i]);
                pth+="->";
            }
            pth+=to_string(spth[spth.size()-1]);
            path.push_back(pth);
        }

        solve(root->left,path,spth);
        solve(root->right,path,spth);
        spth.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<int> spth;

        solve(root,path,spth);

        return path;
    }
};
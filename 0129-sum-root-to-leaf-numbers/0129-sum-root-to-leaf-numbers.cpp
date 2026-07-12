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
    void getpath(TreeNode* root,int &paths,int &p) {
        if (!root)
            return;

        p=p*10+root->val;
        if (!root->left && !root->right) {
            paths+=p;
        }
        
        getpath(root->left, paths, p);
        getpath(root->right, paths, p);
        p/=10;
    }

    int sumNumbers(TreeNode* root) {
        int p=0;
        int paths=0;
        getpath(root, paths,p);
        return paths;
    }
};
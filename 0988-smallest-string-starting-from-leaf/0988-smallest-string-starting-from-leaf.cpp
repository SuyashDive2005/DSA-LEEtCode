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
    void lexi(TreeNode* root,string &curr,string &ans){
        if(!root) return;

        curr.insert(curr.begin(),'a'+root->val);
        if(!root->left && !root->right){
            if(ans.empty() || ans>curr){
                ans=curr;
            }
        }
        lexi(root->left,curr,ans);
        lexi(root->right,curr,ans);
        curr.erase(curr.begin());
    }

    string smallestFromLeaf(TreeNode* root) {
        string curr="";
        string ans="";
        lexi(root,curr,ans);
        return ans;
    }
};
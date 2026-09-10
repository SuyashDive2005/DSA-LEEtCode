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
    int cnt=0;
    int dfs(TreeNode* root,int &nodecnt) {
        if (!root){
            nodecnt=0;
            return 0;
        }

        int sum=0;
        int leftn,rightn;
        int leftsum = dfs(root->left,leftn);
        int rightsum = dfs(root->right,rightn);

        sum = root->val + leftsum + rightsum;
        nodecnt=1+leftn+rightn;

        int avg = round(sum/nodecnt);
        if(avg==root->val) {
            cnt++;
        }
        return sum;
    }
    int averageOfSubtree(TreeNode* root) {
        int nodecnt;
        dfs(root,nodecnt);
        return cnt;
    }
};
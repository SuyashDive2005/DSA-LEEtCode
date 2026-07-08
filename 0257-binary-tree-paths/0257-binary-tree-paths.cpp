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
    void solve(TreeNode* root, vector<string>& ans, vector<int>& path) {

    // Base Case:
    // If there is no node, there is nothing to explore.
    if (root == nullptr)
        return;

    // Add the current node to our current root-to-current path.
    // Think of it as: "I have entered this node."
    path.push_back(root->val);

    // If the current node is a leaf,
    // then the current 'path' already represents
    // one complete Root -> Leaf path.
    if (root->left == nullptr && root->right == nullptr) {

        string currPath = "";

        // Convert vector<int> into the required format:
        // Example:
        // [1,2,5] -> "1->2->5"
        for (int i = 0; i < path.size() - 1; i++) {
            currPath += to_string(path[i]);
            currPath += "->";
        }

        currPath += to_string(path.back());

        // Store this complete path.
        ans.push_back(currPath);
    }

    // Continue exploring the left subtree.
    solve(root->left, ans, path);

    // Continue exploring the right subtree.
    solve(root->right, ans, path);

    // IMPORTANT (Backtracking):
    //
    // We have completely finished exploring this node
    // (both its left and right subtrees).
    //
    // Now we are returning to its parent.
    //
    // Since we are no longer on this node,
    // remove it from the current path.
    //
    // This restores the path exactly as it was before
    // entering this node.
    //
    // Example:
    //
    //      1
    //     /
    //    2
    //   /
    //  4
    //
    // Current path = [1,2,4]
    //
    // After returning from node 4,
    // path should become [1,2]
    //
    // Otherwise, when exploring another branch,
    // the old node (4) would incorrectly remain
    // in the path.
    path.pop_back();
}

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        vector<int> spth;

        solve(root,path,spth);

        return path;
    }
};
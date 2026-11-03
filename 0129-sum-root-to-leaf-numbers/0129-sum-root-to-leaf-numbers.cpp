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
    int SumRec(TreeNode* root, int sum) {
        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr) {
            sum = 10 * sum + root->val;
            return sum;
        }

        int leftSum = SumRec(root->left, 10 * sum + root->val);
        return leftSum + SumRec(root->right, 10 * sum + root->val);
    }

    int sumNumbers(TreeNode* root) {
        return SumRec(root, 0);
    }
};
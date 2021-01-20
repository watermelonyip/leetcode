/*
输入一个二叉树，该函数输出它的镜像。限制：0 <= 节点个数 <= 1000。
思路：左右节点交换，递归。也可以用循环的方法。时间复杂度O(n)，空间复杂度O(n)。n为二叉树的节点数量。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left != nullptr)
            mirrorTree(root->left);
        if(root->right != nullptr)
            mirrorTree(root->right);
        return root;
    }
};

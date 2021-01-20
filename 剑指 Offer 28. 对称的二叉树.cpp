/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。限制：0 <= 节点个数 <= 1000。
思路：判断该二叉树的镜像和本身是否相等，用递归的方法。时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点数量。
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        if(root->left == nullptr && root->right == nullptr)
            return true;
        if(root->left == nullptr || root->right == nullptr)
            return false;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        if(left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

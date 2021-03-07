/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。限制：0 <= 树的结点个数 <= 10000.
思路：一个简单的想法是从上往下计算当前节点的左右子树深度，判断两边深度差是否小于等于1，但是这种方法会导致重复计算很多节点的深度。因此改用后序遍历的方法。
从根节点开始，判断左右子树是否也为平衡树，在调用过程中同时计算深度。时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点个数。
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* root, int &depth){
        if(root == nullptr){
            depth = 0;
            return true;
        }
        int left, right;
        if(isBalanced(root->left, left) && isBalanced(root->right, right)){
            depth = max(left, right) + 1;
            if(abs(left - right) <= 1)
                return true;
        }
        return false;
    }
};

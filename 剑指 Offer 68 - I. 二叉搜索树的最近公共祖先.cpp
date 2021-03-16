/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
说明:所有节点的值都是唯一的。p、q 为不同节点且均存在于给定的二叉搜索树中。
思路：自上往下遍历二叉树，因为是搜索树，所以在遍历时，若当前节点的值都小于p、q的值，就往右子树走；若当前节点的值都大于p、q的值，就往左子树走；若当前节点的值在p、q的值之间，则找到了该节点。
时间复杂度O(n)，空间复杂度O(1)，其中n为二叉树节点个数。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        TreeNode* tree = root;
        while(tree != nullptr){
            /*
            if((tree->val >= p->val && tree->val <= q->val) || 
                tree->val <= p->val && tree->val >= q->val)
                return tree;
            else if(tree->val > p->val && tree->val > q->val)
                tree = tree->left;
            else
                tree = tree->right;
            */
            if(tree->val > p->val && tree->val > q->val)
                tree = tree->left;
            else if(tree->val < p->val && tree->val < q->val)
                tree = tree->right;
            else
                return tree;
        }
        return nullptr;
    }
};

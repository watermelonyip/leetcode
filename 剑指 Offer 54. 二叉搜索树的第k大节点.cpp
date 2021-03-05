/*
给定一棵二叉搜索树，请找出其中第k大的节点。限制：1 ≤ k ≤ 二叉搜索树元素个数。
思路：中序遍历能得到二叉搜索树的升序排列，但是题目需要找到第k大节点，所以要稍微改动，在中序遍历时，先遍历右子树再遍历根节点最后遍历左子树。
注意在遍历的时候k是引用类型，因为要不断修改k的值。
时间复杂度O(n)，空间复杂度O(n)，其中n为二叉搜索树节点个数。
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
    int kthLargest(TreeNode* root, int k) {
        if(root == nullptr)
            return 0;
        return Inorder(root, k); 
    }

    int Inorder(TreeNode* root, int& k){
        if(k >= 1 && root->right != nullptr){
            int result = Inorder(root->right, k);
            if(k == 0)
                return result;
        }
        
        if(k-- == 1)
            return root->val;
        //k--;
        if(k >= 1 && root->left != nullptr){
            int result = Inorder(root->left, k);
            if(k == 0)
                return result;
        }
        return root->val;
    }
};

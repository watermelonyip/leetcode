/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。提示：节点总数 <= 1000。
思路：层次遍历二叉树，用队列（和广度优先搜索一样）。时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点数量。
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            result.push_back(t->val);
            q.pop();
            if(t->left != nullptr)
                q.push(t->left);
            if(t->right != nullptr)
                q.push(t->right);
        }
        return result;
    }
};

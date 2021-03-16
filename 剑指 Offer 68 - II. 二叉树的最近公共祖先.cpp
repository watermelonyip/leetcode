/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
思路：

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
        /*
        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        vector<TreeNode*> pathA;
        vector<TreeNode*> pathB;
        getPath(root, p, pathA);
        getPath(root, q, pathB);
        if(pathA.size() == 0 || pathB.size() == 0)
            return nullptr;
        TreeNode* result = root;
        for(int i = 0; i < pathA.size() && i < pathB.size(); i++){
            if(pathA[i] == pathB[i])
                result = pathA[i];
            else
                break;
        }
        return result;
        */
        if(root == nullptr || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left == nullptr)
            return right;
        if(right == nullptr)
            return left;
        return root;
    }

    bool getPath(TreeNode* root, TreeNode* target, vector<TreeNode*> &path){
        path.push_back(root);
        if(root == target)
            return true;
        if(root->left != nullptr){
            if(getPath(root->left, target, path))
                return true;
            else
                path.pop_back();
        }
        if(root->right != nullptr){
            if(getPath(root->right, target, path))
                return true;
            else
                path.pop_back();
        }
        return false;
    }
};

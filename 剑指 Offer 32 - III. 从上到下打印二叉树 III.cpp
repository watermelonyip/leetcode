/*
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
提示：节点总数 <= 1000。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        stack<TreeNode*> s1; //从左往右
        stack<TreeNode*> s2;    //从右往左
        vector<int> level;
        int currentorder = 0;   //  从左往右：0，从右往左：1
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            if(currentorder == 0){
                while(!s1.empty()){
                    TreeNode* t = s1.top();
                    level.push_back(t->val);
                    s1.pop();
                    if(t->left != nullptr)
                        s2.push(t->left);
                    if(t->right != nullptr)
                        s2.push(t->right);
                }
            }
            else{
                while(!s2.empty()){
                    TreeNode* t = s2.top();
                    level.push_back(t->val);
                    s2.pop();
                    if(t->right != nullptr)
                        s1.push(t->right);
                    if(t->left != nullptr)
                        s1.push(t->left);
                }
            }
            currentorder = 1 - currentorder;
            result.push_back(level);
            level.clear();
        }
        return result;
    }
};

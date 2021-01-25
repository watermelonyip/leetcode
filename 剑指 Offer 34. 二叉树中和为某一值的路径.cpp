/*
输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。提示：节点总数 <= 10000。
思路：前序遍历递归，当前遍历到根节点时，判断是否和sum值相等，如果不相等则返回到上一层。时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点数量。
写的过程中犯了个错，在递归过程中如果不是根节点并且当前累加值加上当前节点值大于sum值则退出这层递归，这个想法非常错误，因为节点的值可能是负数！！

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == nullptr)
            return result;
        vector<int> currentresult;
        pathSum(root, sum, 0, result, currentresult);
        return result;
    }

    void pathSum(TreeNode* root, int sum, int current, vector<vector<int>> &result, vector<int> &currentresult){
        //cout << current <<  "  "<< abs(current + root->val) << endl;
        if(root->left == nullptr && root->right == nullptr){
            if((current + root->val) == sum){
                currentresult.push_back(root->val);
                result.push_back(currentresult);
                currentresult.pop_back();
            }
        }
        current += root->val;
        currentresult.push_back(root->val);
        if(root->left != nullptr)
            pathSum(root->left, sum, current, result, currentresult);
        if(root->right != nullptr)
            pathSum(root->right, sum, current, result, currentresult);
        currentresult.pop_back();
    }
};

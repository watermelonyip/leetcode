/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。提示：节点总数 <= 1000。
思路：对比上一题，多增加两个变量，一个用于在队列插入元素时统计下一层节点的个数，另一个用于计数并判断当前行的元素是否打印完成。时间复杂度O(n)，空间复杂度O(n)，其中n为二叉树节点个数。
看了大佬的题解可知，不需要专门的变量计算下一层节点个数，直接用调用计算队列元素个数便知道当前行的节点数量。
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
        int nextnum = 0;
        int currentnum = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            TreeNode* t = q.front();
            level.push_back(t->val);
            q.pop();
            currentnum--;
            if(t->left != nullptr){
                nextnum++;
                q.push(t->left);
            }
            if(t->right != nullptr){
                nextnum++;
                q.push(t->right);
            }
            if(currentnum == 0){
                currentnum = nextnum;
                nextnum = 0;
                result.push_back(level);
                level.clear();
            }
        }
        return result;
    }
};

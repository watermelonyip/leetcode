/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)B是A的子结构， 即A中有出现和B相同的结构和节点值。
限制：0 <= 节点个数 <= 10000
思路：用递归的方法，遍历树A，如果当前根节点和树B根节点相同，则往下走继续判断；否则树A继续往下遍历。
在判断过程中如果树B节点为空，则表示遍历完成，返回true；如果树A节点为空，则表示树A遍历完成，不包含树B。
时间复杂度O(MN)，空间复杂度O(M)。其中M，N分别为树A和树B的节点数量。
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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool result = false;
        if(A != nullptr && B != nullptr){
            if(A->val == B->val)
                result = iterate(A, B);
            if(!result)
                result = isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
        return result;
    }
    bool iterate(TreeNode* A, TreeNode* B){
        if(B == nullptr)
            return true;
        if(A == nullptr)
            return false;
        if(A->val != B->val)
            return false;
        return iterate(A->left, B->left) && iterate(A->right, B->right);
    }
};

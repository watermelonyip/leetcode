/*
输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回：
    3
   / \
  9  20
    /  \
   15   7

限制：0 <= 节点个数 <= 5000

思路：使用递归，前序遍历的第一个节点为当前树（子树）的根结点，在中序遍历中找到该节点，该节点左边的为其左子树，右边为其右子树，一直递归下去。时间复杂福O(n)，空间复杂度O(n)。非递归方法还没掌握，继续跟进。
卡住的点：元素只有一个的时候的处理；vector初始化问题要注意，比如vector<int> pre(preorder.begin(), preorder.begin() + 1)里面只有preorder[0]这个元素。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() <= 0 || inorder.size() <= 0 || preorder.size() != inorder.size())
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1)
            return root;
        /*
        for(int i = 0; i < preorder.size(); i++)
            cout << preorder[i] << " ";
        cout << endl;
        for(int i = 0; i < inorder.size(); i++)
            cout << inorder[i] << " ";
        cout << endl;
        */

        int index = 0;
        for(; index < inorder.size(); index++){
            if(inorder[index] == preorder[0])
                break;
        }
        //cout << "index: " << index << endl;
        if(index == 0){ // no left node
            root->left = NULL;
        }
        else if(index == 1){
            root->left = new TreeNode(inorder[0]);
        }
        else{
            vector<int> pre(preorder.begin() + 1, preorder.begin() + index + 1);
            vector<int> ino(inorder.begin(), inorder.begin() + index);
            //cout << pre.size() << " !!"  << ino.size() << endl;
            root->left = buildTree(pre, ino);
        }

        if(index == inorder.size() - 1){   // no right node
            root->right = NULL;
        }
        else if(index == inorder.size() - 2){
            root->right = new TreeNode(inorder[inorder.size() - 1]);
        }
        else{
            vector<int> pre(preorder.begin() + index + 1, preorder.end());
            vector<int> ino(inorder.begin() + index + 1, inorder.end());
            root->right = buildTree(pre, ino);
        }
        return root;
    }
};



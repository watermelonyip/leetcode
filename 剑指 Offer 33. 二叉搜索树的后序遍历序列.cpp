/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
提示：数组长度 <= 1000。
思路：后序遍历最后一个节点为根节点，根据二叉搜索树的特点，小于根节点的在左子树，大于根节点的在右子树，因此能把数组分为两部分。不断递归下去。
特殊情况处理，后序遍历为[]时，也返回true。时间复杂度O(n^2)，空间复杂度O(n)，其中n为二叉搜索树节点数量。
题解有使用单调栈的方法。
*/
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if(postorder.size() <= 0)
            return true;
        int root = postorder[postorder.size() - 1];
        int left = 0;
        for(; left < postorder.size() - 1; left++){
            if(postorder[left] > root)
                break;
        }
        for(int right = left; right < postorder.size() - 1; right++){
            if(postorder[right] < root)
                return false;
        }
        //cout << root << "   " << left << endl;
        bool lefttree = true;
        if(left > 0){
            vector<int> leftpart(postorder.begin(), postorder.begin() + left);
            lefttree = verifyPostorder(leftpart);
        }
        bool righttree = true;
        if(left < postorder.size() - 1){
            vector<int> rightpart(postorder.begin() + left, postorder.end() - 1);
            righttree = verifyPostorder(rightpart);
        }
        return lefttree && righttree;
    }
};

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
思路：根据二叉搜索树的特点，使用中序遍历，转换后，根节点的左节点指向左子树的最后节点，根节点的右节点指向右子树的最前节点。最后还要将头尾节点链接起来。因此使用递归的方法。
需要特别注意的是，用lastNode来记录根节点需要链接的最后节点，所以在调用时传入引用类型。时间复杂度O(n)，空间复杂度O(n)，n为二叉树节点数量。
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return root;
        Node* lastNode = nullptr;
        convertTree(root, &lastNode);
        Node* head = lastNode;
        while(head != nullptr && head->left != nullptr)
            head = head->left;
        head->left = lastNode;
        lastNode->right = head;
        return head;
    }

    void convertTree(Node* root, Node** lastNode){
        if(root == nullptr)
            return;
        if(root->left != nullptr)
            convertTree(root->left, lastNode);
        
        root->left = *lastNode;
        if(*lastNode != nullptr)
            (*lastNode)->right = root;
        
        *lastNode = root;
        if(root->right != nullptr)
            convertTree(root->right, lastNode);
    }
};

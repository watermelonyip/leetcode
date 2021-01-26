/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
提示：-10000 <= Node.val <= 10000。Node.random 为空（null）或指向链表中的节点。节点数目不超过 1000 。
思路：按照剑指的方法，先遍历一遍将原链表的next复制一遍，然后再遍历一遍处理random指针，最后将链表拆分回原链表和复制后的链表。时间复杂度O(n)，空间复杂度O(1)，其中n为链表节点数量。
有其他方法：直接复制，然后每个节点从头遍历找到random指针，时间复杂度O(n^2)，空间复杂度O(1)。或者用哈希表来存储random节点，时间复杂度O(n)，空间复杂度O(n)。
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return head;
        Node* node = head;
        while(node != nullptr){
            Node* temp = new Node(node->val);
            temp->next = node->next;
            temp->random = NULL;
            node->next = temp;
            node = temp->next;
        }
        node = head;
        while(node != nullptr){
            if(node->random != nullptr)
                node->next->random = node->random->next;
            node = node->next->next;
        }
        node = head;
        Node* copyList = head->next;
        Node* node2 = copyList;
        while(node != nullptr){
            node->next = node2->next;
            if(node->next == nullptr)
                node2->next = nullptr;
            else
                node2->next = node->next->next;
            node = node->next;
            node2 = node2->next;
        }
        /*
        node = head;
        while(node != nullptr){
            cout << node->val << "  ";
            node = node->next;
        }
        */
        return copyList;
    }
};

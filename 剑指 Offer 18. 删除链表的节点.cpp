/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。返回删除后的链表的头节点。
注意：此题对比原题有改动。
题目保证链表中节点的值互不相同。
若使用 C 或 C++ 语言，你不需要 free 或 delete 被删除的节点。

思路：遍历，记录当前节点，当前节点的前一个节点，修改引用。注意删除头节点和尾节点的操作。时间复杂度O(n)，空间复杂度O(1)。

如果题目是给定头节点和要删除的节点，直接复制要删除节点的后一个节点内容到要删除节点，再修改下一个节点引用。时间复杂度O(1)，空间复杂度O(1)。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        if(head->val == val)
            return head->next;
        ListNode* pre = head;
        ListNode* p = head->next;
        while(p != NULL){
            if(p->val == val){
                if(p->next != NULL){
                    pre->next = p->next;
                }
                else{
                    pre->next = NULL;
                }
                //p = NULL;
                break;
            }
            pre = p;
            p = p->next;
        }
        return head;
    }
};

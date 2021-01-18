/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
思路：用三个节点来记录，前两个用来调整链表方向，还有一个用来记录下一个节点，防止调整方向后断链。时间复杂度：O(n)，空间复杂度O(1)。也可以使用递归，比较麻烦。
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* p3 = head;
        p1->next = NULL;
        while(p2 != NULL){
            p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        head = p1;
        return head;
    }
};

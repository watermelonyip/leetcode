/*
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

思路：题目的意思即找到n-k+1个点。用快慢指针的思想，快指针先走k-1步，然后快慢指针一起走，当快指针走到最后节点时，慢指针刚好在n-k+1位置。
题目拓展：找到中间节点，也是用快慢指针思想，快指针走两步，慢指针走一步，当快指针走到最后节点时，慢指针刚好在中间节点。
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if(head == NULL || k <= 0)
            return nullptr;
        ListNode* low = head;
        ListNode* fast = head;
        for(int i = 0; i < k - 1; i++){
            if(fast->next != NULL)
                fast = fast->next;
            else
                return nullptr;
        }
        while(fast->next != NULL){
            low = low->next;
            fast = fast->next;
        }
        return low;
    }
};

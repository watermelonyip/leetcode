/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。限制：0 <= 链表长度 <= 1000
思路：用头指针记录合并链表的头指针，用两个指针分别记录两个链表当前位置，用一个指针记录合并链表的位置。时间复杂度O(M+N)，空间复杂度O(1)。
也可以使用递归的方法。不知道为啥递归好像更快，可能测试用例比较小吧？
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head = l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if(l1->val > l2->val){
            head = l2;
            p2 = p2->next;
        }
        else
            p1 = p1->next;
        ListNode* p_next = head;
        while(p1 != NULL && p2 != NULL){
            if(p1->val < p2->val){
                p_next->next = p1;
                p1 = p1->next;
            }
            else{
                p_next->next = p2;
                p2 = p2->next;
            }
            p_next = p_next->next;
        }
        if(p1 != NULL)
            p_next->next = p1;
        else
            p_next->next = p2;
        return head;
        
        /*
        //以下为递归方法
         if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        ListNode* head = l1;
        if(l1->val > l2->val){
            head = l2;
            head->next = mergeTwoLists(l1, l2->next);
        }
        else{
            head->next = mergeTwoLists(l1->next, l2);
        }
        return head;
        */
    }
};

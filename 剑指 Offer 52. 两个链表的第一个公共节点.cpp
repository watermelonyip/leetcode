/*
输入两个链表，找出它们的第一个公共节点。
注意：如果两个链表没有交点，返回 null.在返回结果后，两个链表仍须保持原有的结构。可假定整个链表结构中没有循环。程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
思路：如果不考虑内存，可以用哈希表，或者用栈来处理。用哈希表可以从链表从头到尾判断，从栈可以从链表从尾到头处理。
因为单链表节点只有一个next指针，所以从两个链表尾节点开始，往前找到最后一个相同的节点（即第一个不相同的节点的next节点）即为第一个公共节点。
如果是O(1)内存，那么先分别计算两个链表的长度，并且让长的链表先走几步，使得他们同时遍历时长度一样。然后同时遍历两个链表找到第一个相同的节点。
时间复杂度O(m+n)，空间复杂度O(1)，其中m，n分别为两个链表的长度。

看完题解https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/solution/jian-zhi-offer-52-liang-ge-lian-biao-de-gcruu/
觉得这种双指针方法更妙。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        int lengthA = 0, lengthB = 0;
        for(ListNode* p = headA; p != nullptr; p = p->next)
            lengthA++;
        for(ListNode* p = headB; p != nullptr; p = p->next)
            lengthB++;
        ListNode* longList = headA;
        ListNode* shortList = headB;
        int lengthdifference = abs(lengthA - lengthB);
        if(lengthA < lengthB){
            longList = headB;
            shortList = headA;
        }
        for(; lengthdifference > 0; lengthdifference--)
            longList = longList->next;
        while(longList != nullptr && shortList != nullptr){
            if(longList == shortList)
                return longList;
            longList = longList->next;
            shortList = shortList->next;
        }
        return nullptr;
    }
};

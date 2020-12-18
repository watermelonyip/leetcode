/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
思路：用栈或者递归来实现，但是递归可能导致暴栈，还是用栈比较好。
时间复杂度：O(n)，空间复杂度：O(n)
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
    vector<int> reversePrint(ListNode* head) {
        stack<ListNode*> s;
        vector<int> result;
        if(head == NULL)
            return result;
        ListNode* p = head;
        while(p != NULL){
            s.push(p);
            p = p->next;
        }
        while(!s.empty()){
            result.push_back(s.top()->val);
            s.pop();
        }
        return result;
    }
};

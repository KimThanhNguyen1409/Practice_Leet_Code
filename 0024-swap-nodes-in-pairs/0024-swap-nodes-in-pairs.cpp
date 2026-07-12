/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;
        while(pre->next != nullptr && pre->next->next != nullptr){
            ListNode *curr = pre->next;
            ListNode *n = curr->next;
            curr->next = n->next;
            n->next = curr;
            pre->next = n;
            pre = curr;
        }
        return dummy.next;
    }
};
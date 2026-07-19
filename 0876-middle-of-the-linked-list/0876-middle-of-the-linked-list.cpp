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
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *co = head;
        int count = 0;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        while(co->next != nullptr){
            co = co->next;
            count++;
        }
        ListNode *ans = slow;
        if(count % 2 != 0)
            return ans->next;
        return ans;
    }
};
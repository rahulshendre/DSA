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
    void reorderList(ListNode* head) {
        //first element is the same, so head doesn't change it's position
        //we have a list, now we reverse the list and then merge it 
        if(!head || !head->next){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the list
        ListNode* prev = nullptr;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        ListNode* first = head, *second = prev;
        while(second->next){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
        
    }
};
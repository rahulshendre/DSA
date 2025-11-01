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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // unordered_map<int,int> mpp;

        // for(int num : nums){
        //     mpp[num]++;
        // }
        // ListNode* dummy = new ListNode(0, head);
        // ListNode* prev = dummy;
        // ListNode* curr = head;

        // while(curr != nullptr){
        //     if(mpp.count(curr->val)){
        //         prev -> next = curr -> next;
        //     }
        //     else{
        //         prev = curr;
        //     }
        //     curr = curr->next;
        // }
        // return dummy->next;

        unordered_set<int> mpp(nums.begin(), nums.end());

        while(head && mpp.count(head->val)){
            head = head->next;
        }
        ListNode* curr = head;
        while(curr && curr->next){
            //upar wala is just talkig about exitence of the lenght
            //this lower ones will tell us, if that thing we have tells
            // 
            while(curr->next && mpp.count(curr->next->val)){
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
        return head;
    }
};
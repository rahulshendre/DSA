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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;

        while(head != nullptr){
            ListNode* temp;
            temp = head->next;
            head->next = node;
            node = head;
            head = temp;
        }
        return node;
    }
};
//what we do to reverse linked list is add a node which is essentially a nullptr here because here we need the number to be able to store address of others too
/* so what we did here was 
eg: 1->2->nullptr
made a temp = stored head->next which is 2
then we said head->next = node=nullptr
then we said that head = node
bringing a empty nullptr ahead of 1 
then we say that head = temp temp had the value 2 which is now stored in the head, which was empty before 
so now we have 2->1->nullptr

*/


//how to swap using temp
/* suppose you have two numbers a and b, you want to swap them 
now you take the value of a and store in a temporary variable
ok.
now you make a and b equal so now a has the value of b
correct, so essentially both are equal and are now equal to b
now you give b the value of temp
which was a previously
great 
now a has the value of b and b has the value of a 
simply beacuse we stored the value of a in temp for some time
*/
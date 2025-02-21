/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode** prev, struct ListNode** current) {
    struct ListNode* temp = *current;
    if (*prev == NULL) { // If the node to delete is the head
        *current = (*current)->next; // Move to the next node
    } else {
        (*prev)->next = (*current)->next; // Link previous node to the next node
        *current = (*current)->next;     // Update current to the next node
    }
    free(temp); // Free the node
}

// Corrected removeElements function
struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *current = head;
    struct ListNode *prev = NULL;

    while (current != NULL) {
        if (current->val == val) {
            deleteNode(&prev, &current);
            if (prev == NULL) {
                head = current; // Update head if the first node was removed
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    return head;
}

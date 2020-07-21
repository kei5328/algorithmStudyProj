/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// main algorithm
struct ListNode* reverseList(struct ListNode* head)
{
    struct ListNode * p_prev = NULL;
    struct ListNode * p_curr = NULL;
    struct ListNode * p_next = NULL;
    uint8_t init = 0;
    if ( head == NULL ) return head;
    p_curr = head;
    while (p_curr!=NULL)
    {
        p_next = p_curr->next;
        p_curr->next = p_prev;

        p_prev = p_curr;
        p_curr = p_next;
    }
    return p_prev;
}

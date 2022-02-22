/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head){
    //
    if (head==NULL) // head is null: no list
        return head;
    struct ListNode * p_temp1  = head;
    struct ListNode * p_temp2 = head->next;
    if (p_temp2==NULL) // there is only one node.
        return head;

    // deal with the first pair
    head->next = p_temp2->next;
    p_temp2->next = head;
    head = p_temp2;

    if (p_temp1->next==NULL) // only two nodes
        return head;
    p_temp2 = p_temp1->next->next;

    while (p_temp1->next!=NULL && p_temp2!=NULL)
    {
        p_temp1->next->next = p_temp2->next;
        p_temp2->next = p_temp1->next;
        p_temp1->next = p_temp2;

        p_temp1=p_temp2->next;
        if (p_temp1->next == NULL)
        {
            break;
        }
        p_temp2 = p_temp1->next->next;
    }
    return head;
}



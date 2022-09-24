/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){

    ListNode* p_tmp1 = NULL;
    ListNode* p_tmp2 = NULL;
    if (head==NULL) return NULL;

    // first deal with the case of head being same as the val.
    while (head!=NULL && head->val==val)
    {
        // simply skip to the next one. continue until the value is not the same or it points to null(end of list).
        head = head->next;
    }

    // head val is not the same as val at this point.
    // if all list had the same value as val, the head here would be null.
    if (head==NULL) return NULL;

    // head is not NULL so we can reference.
    p_tmp1 = head;
    p_tmp2 = head->next;

    while (p_tmp2!=NULL)
    {
        if (p_tmp2->val==val)
        {// matches
            //set tmp1 next to the tmp2's next(skip tmp2)
            p_tmp1->next = p_tmp2->next;
            // proceed to the next.
            p_tmp2 = p_tmp2->next;
        }
        else
        {   // do not change anything.
            // move both pointers to the next one.
            p_tmp1 = p_tmp2;
            p_tmp2 = p_tmp2->next;
        }

    }
    return head;
}

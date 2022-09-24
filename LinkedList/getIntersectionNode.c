/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

uint16_t find_list_length(struct ListNode * p_node)
{
    uint16_t list_cnt = 0;
    while (p_node!=NULL)
    {
        list_cnt++;
        p_node = p_node->next;
    }
    return list_cnt;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {


    uint16_t a_cnt = find_list_length(headA);
    uint16_t b_cnt = find_list_length(headB);


    if (a_cnt<b_cnt)
    {// traverse the b so that remaining nodes would be the same length as a
        for (int ii = b_cnt; ii>a_cnt; ii--)
        {
            if (headB==NULL) return NULL; // handling the null pointer in case.
            headB = headB->next;
        }
    }
    else if (b_cnt<a_cnt)
    {// traverse the b so that remaining nodes would be the same length as a
        for (int ii = a_cnt; ii>b_cnt; ii--)
        {
            if (headA==NULL) return NULL; // handling the null pointer in case.
            headA = headA->next;
        }

    }

    // traverse the rest and see if the address are the same
    while (headA!=NULL && headB!=NULL)
    {
        if (headA==headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}



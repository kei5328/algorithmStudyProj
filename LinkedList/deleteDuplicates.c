/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


// Remove the duplicated nodes in place
struct ListNode* deleteDuplicates(struct ListNode* head){

    if (head == NULL) return head;
    struct ListNode * curr = head->next;
    struct ListNode * last = head;
    struct ListNode * tmp = head;

    while (curr!=NULL)
    {// there are more connected nodes
      if (curr->val == last->val)
      { // the current node is a duplicate(it's sorted already)

        // keep the last the proceed to next
        tmp = curr;
        curr = curr->next;
        last->next = NULL;
        // is freeing malloced current node necessary?(it's better to do it)
        free(tmp);
      }
      else
      {// it's not a duplicate
        last->next = curr;
        last = curr;
        curr = curr->next;
      }
    }
    return head;
}

// Comments:
/*
Initially, I did not consider the case where the last node is a duplicate.
Also, I did not really need to use two different list nodes(curre and head) since I can keep on traversing

*/

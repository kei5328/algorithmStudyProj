/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head){
    // first count how many nodes are there
    int cnt=0; // count of the nodes.
    struct ListNode* temp = head;
    while (temp!=NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (cnt==1) return true;

    uint8_t nums[cnt]; // allocate memory for the array

    cnt = 0; // reset cnt;
    temp = head; // reset temp
    while (temp!=NULL)
    {
        nums[cnt] = temp->val;
        temp = temp->next;
        cnt++;
    }

    int jj = cnt-1;
    for (int ii = 0; ii<jj; ii++ )
    {
        if (nums[ii]!=nums[jj])
            return false;
        jj--;
    }
    return true;
}


// 2nd answer
struct ListNode* reverse_list(struct ListNode * head)
{
    if (head==NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode * curr_node = head->next;
    struct ListNode * next_node = NULL;
    head->next = NULL;
    while (curr_node!=NULL)
    {
        next_node = curr_node->next;
        curr_node->next = head;
        head = curr_node;
        curr_node = next_node;
    }

    curr_node = head;
    while (curr_node!=NULL)
    {
        next_node = curr_node->next;
        curr_node = next_node;
    }
    return head;
}
//
bool isPalindrome(struct ListNode* head){
    // first count how many nodes are there
    int cnt=0; // count of the nodes.
    int total_num;
    struct ListNode* temp = head;
    while (temp!=NULL)
    {
        temp = temp->next;
        cnt++;
    }
    total_num = cnt;

    if (cnt==1) return true;
    cnt = 0; // reset cnt;
    temp = head; // reset temp

    while (temp!=NULL && cnt< (total_num/2)-1 )
    {
        temp = temp->next;
        cnt++;
    }
    struct ListNode * tip = temp;
    if (total_num%2==0)
    {
        tip = tip->next;
    }
    else
    {
        tip = tip->next;
        tip = tip->next;
    }
    tip = reverse_list(tip);

    temp = head; // reset temp.
    for (int ii = 0; (tip!=NULL && temp!=NULL); ii++)
    {
        if (tip->val!=temp->val)
        {
            return false;
        }
        tip= tip->next;
        temp = temp->next;
    }
    return true;
}





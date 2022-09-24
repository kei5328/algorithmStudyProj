/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    if (node==NULL || node->next==NULL) return;

    struct ListNode * next_node = node->next;
    node->next = next_node->next;
    node->val = next_node->val;
    free(next_node);
}

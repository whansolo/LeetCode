/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *temp = node->next;
    //copy of next node
    node->val = node->next->val;
    node->next = node->next->next;

    //delete next node
    free(temp);
}

//or
/*
void deleteNode(struct ListNode* node){
    *node = *node->next;
}
*/

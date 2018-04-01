/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 bool hasCycle(struct ListNode *head) {
     if(head == NULL || head->next == NULL) return 0;
     struct ListNode *slow = head;
     struct ListNode *fast = head->next;

     while(slow != fast){
         if(fast == NULL || fast->next == NULL) return 0;
         slow = slow->next;
         fast = fast->next->next;
     }
     return 1;
 }
/* also can be written as followed. */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return 1;
    }
    return 0;
}

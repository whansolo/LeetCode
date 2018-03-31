/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*** iterative solution ***/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->next = NULL;

    struct ListNode* ptr = head;

    while(l1 && l2){
        if(l1->val < l2->val){
            ptr->next = l1;
            l1 = l1->next;
        }
        else{
            ptr->next = l2;
            l2 = l2->next;
        }
        ptr = ptr->next;
    }
    if(l1) ptr->next = l1;
    else ptr->next = l2;

    return head->next;
}

/***  recursive solution  ***/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

/*** pointer to the entry pointer ***/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode head;
    struct ListNode **write = &head.next;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            *write = l1;
            l1 = l1->next;
        }
        else {
            *write = l2;
            l2 = l2->next;
        }
        write = &(*write)->next;
    }
    *write = l1 ?: l2;
    return head.next;
}

/*
 * used the tricky skill from which Linus once said “People who understand
 * pointers just use a “pointer to the entry pointer”, and initialize that
 * with the address of the list_head. And then as they traverse the list,
 * they can remove the entry without using any conditionals, by just doing
 * a “*pp = entry->next””
 */

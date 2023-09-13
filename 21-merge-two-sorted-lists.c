/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode* tmp = NULL;
    struct ListNode* head = NULL;

    // Edge cases
    if (!list1 && !list2)
        return head;
    
    if (!list1)
        return list2;

    if (!list2)
        return list1;

    if (list1->val <= list2->val) {
        tmp = list1;
        list1 = list1->next;
    } else {
        tmp = list2;
        list2 = list2->next;
    }
    head = tmp;

    // Main cases
    while (list1 && list2) {
        // Traversing the list
        struct ListNode **branch = NULL;
        branch = (list1->val <= list2->val) ? &list1 : &list2;

        tmp->next = *branch;
        *branch = (*branch)->next;
        tmp = tmp->next;
    }

    // If one of list exhausted
    if (list1 == NULL)
        tmp->next = list2;
    else if (list2 == NULL)
        tmp->next = list1;

    return head;
}
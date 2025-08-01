#ifndef LIST_FUNCTIONS_H
#define LIST_FUNCTIONS_H

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef ListNode* List;

void* makelist(int n);
void* append(int n, void* list);
void* tail(void* list);
void* divide(int n, void* list);
int sum(void* list);
int equal(void* list);
void free_list(void* list);

#endif /* LIST_FUNCTIONS_H */

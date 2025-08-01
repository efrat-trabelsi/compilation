#include <stdio.h>
#include <stdlib.h>
#include "list_functions.h"

void* makelist(int n) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (!node) return NULL;
    node->value = n;
    node->next = NULL;
    return (void*)node;
}

void* append(int n, void* list) {
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (!new_node) return list;
    new_node->value = n;
    new_node->next = NULL;
    
    if (list == NULL) {
        return (void*)new_node;
    }
    
    ListNode* current = (ListNode*)list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    
    return list;
}

void* tail(void* list) {
    if (list == NULL) return NULL;
    
    ListNode* head = (ListNode*)list;
    ListNode* new_head = head->next;
    free(head);
    
    return (void*)new_head;
}

void* divide(int n, void* list) {
    if (list == NULL || n == 0) return NULL;
    
    List result = NULL;
    ListNode* current = (ListNode*)list;
    
    while (current != NULL) {
        if (current->value % n == 0) {
            result = (List)append(current->value, result);
        }
        current = current->next;
    }
    
    return (void*)result;
}

int sum(void* list) {
    if (list == NULL) return 0;
    
    int total = 0;
    ListNode* current = (ListNode*)list;
    
    while (current != NULL) {
        total += current->value;
        current = current->next;
    }
    
    return total;
}

int equal(void* list) {
    if (list == NULL) return 1;
    
    ListNode* current = (ListNode*)list;
    int first_value = current->value;
    
    while (current != NULL) {
        if (current->value != first_value) {
            return 0;
        }
        current = current->next;
    }
    
    return 1;
}

void free_list(void* list) {
    ListNode* current = (ListNode*)list;
    while (current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

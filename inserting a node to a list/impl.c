#include "intlist.h"
#include <stdlib.h>

IntListNode *insert_list(IntListNode **head_ptr, int idx, int v) {
    if (idx<0) { return NULL; }
    
    if (*head_ptr==NULL && idx>0) {
        return NULL;
    } else if (idx==0) {
        IntListNode *node = (IntListNode*)malloc(sizeof(IntListNode));
        node->value = v;
        node->next = *head_ptr;
        *head_ptr = node;
        return *head_ptr;
    } else {
        if (insert_list(&((*head_ptr)->next), idx-1, v)==NULL) {
            return NULL;
        } else {
            return *head_ptr;
        }
    }
}

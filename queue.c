#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

/* Notice: sometimes, Cppcheck would find the potential NULL pointer bugs,
 * but some of them cannot occur. You can suppress them by adding the
 * following line.
 *   cppcheck-suppress nullPointer
 */


/* Create an empty queue */
struct list_head *q_new()
{
    // create new head
    struct list_head *head = malloc(sizeof(struct list_head));
    // store next node in pointer
    if (head != NULL) {
        INIT_LIST_HEAD(head);
    }

    return head;
}

/* Free all storage used by queue */
void q_free(struct list_head *l)
{
    if (l == NULL) {
        return;
    }
    while (!list_empty(l)) {
        struct list_head *tmp = l;
        l = l->next;
        list_del(tmp);
        free(tmp);
    }
}

/* Create New Element*/

static inline element_t *new_element(const char *s){
    if(!s){
        return NULL;
    }

    element_t *new = malloc(sizeof(element_t));

    if(!new){
        return NULL;
    }

    size_t len = strlen(s);
    if(len > len + 1){
        free(new);
        return NULL;
    }

    new->value = malloc(len+1);
    if(!new->value){
        free(new);
        return NULL;
    }

    memcpy(new->value, s, len);

    new->value[len] = '\0';
    return new;
}


/* Insert an element at head of queue */
bool q_insert_head(struct list_head *head, char *s)
{
    if(!head){
        return false;
    }

    element_t *new = new_element(s);

    if(!new){
        return false;
    }

    list_add(&new->list, head);


    return true;
}

/* Insert an element at tail of queue */
bool q_insert_tail(struct list_head *head, char *s)
{
    if(!head){
        return false;
    }

    element_t *new = new_element(s);

    if(!new){
        return false;
    }

    list_add_tail(&new->list, head);


    return true;
}

/* Remove element */
static inline element_t *remove_element(element_t *target, char *sp, size_t bufsize){
    if(!target){
        return NULL;
    }

    if(sp && bufsize != 0){
        size_t len = strlen(target->value);
        if(len > bufsize - 1){
            len = bufsize - 1;
        }
        memcpy(sp, target->value, len);
        sp[len] = '\0';
    }

    list_del(&target->list);
    return target;
}

/* Remove an element from head of queue */
element_t *q_remove_head(struct list_head *head, char *sp, size_t bufsize)
{   
    if(!head){
        return NULL;
    }
    return remove_element(list_first_entry(head, element_t, list), sp, bufsize);
}

/* Remove an element from tail of queue */
element_t *q_remove_tail(struct list_head *head, char *sp, size_t bufsize)
{
    if(!head){
        return NULL;
    }
    return remove_element(list_last_entry(head, element_t, list), sp, bufsize);
}

/* Return number of elements in queue */
int q_size(struct list_head *head)
{
    // teach code
    if (!head)
        return 0;

    int len = 0;
    struct list_head *li;

    list_for_each (li, head)
        len++;
    return len;
}

/* Delete the middle node in queue */
bool q_delete_mid(struct list_head *head)
{
    // https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
    return true;
}

/* Delete all nodes that have duplicate string */
bool q_delete_dup(struct list_head *head)
{
    // https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
    return true;
}

/* Swap every two adjacent nodes */
void q_swap(struct list_head *head)
{
    // https://leetcode.com/problems/swap-nodes-in-pairs/
}

/* Reverse elements in queue */
void q_reverse(struct list_head *head) {}

/* Reverse the nodes of the list k at a time */
void q_reverseK(struct list_head *head, int k)
{
    // https://leetcode.com/problems/reverse-nodes-in-k-group/
}

/* Sort elements of queue in ascending order */
void q_sort(struct list_head *head) {}

/* Remove every node which has a node with a strictly greater value anywhere to
 * the right side of it */
int q_descend(struct list_head *head)
{
    // https://leetcode.com/problems/remove-nodes-from-linked-list/
    return 0;
}

/* Merge all the queues into one sorted queue, which is in ascending order */
int q_merge(struct list_head *head)
{
    // https://leetcode.com/problems/merge-k-sorted-lists/
    return 0;
}

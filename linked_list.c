#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef node *List;
typedef enum bool {FALSE, TRUE} Bool;

Bool is_empty(List head);
void print_list(List head);
node *search_item(List head, int item);
Bool push_front(List *hptr, int item);
Bool push_back(List *hptr, int item);
int pop_front(List *hptr);
int pop_back(List *hptr);
Bool delete_item(List *hptr, int item);

/* Uncomment and rewrite main if you want to use it.
int main()
{
    List a=NULL;
    printf("%d", is_empty(a));
    print_list(a);
    printf("%p", search_item(a, 3));
    push_front(&a, 1);
    push_front(&a, 2);
    push_back(&a, 2);
    push_back(&a, 1);
    print_list(a);
    pop_back(&a);
    pop_front(&a);
    print_list(a);
    delete_item(&a, 1);
    delete_item(&a, 2);
    print_list(a);
    printf("%d", pop_front(&a));
}
*/

/* is_empty: checks if the List is empty*/
Bool is_empty(List head)
{
    return head == NULL;
}

/* print_List: prints all the items of the List */
void print_list(List head)
{
    node *temp = head;

    if (is_empty(head)) {
        printf("Empty List");
    }

    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp -> next;   
    }
    printf("\n");
}

/* search_item: returns the pointer to the node
                if the given item is in the List */
node *search_item(List head, int item)
{
    node *temp = head;

    while (temp != NULL && temp->data != item)
        temp = temp -> next;

    return temp;
}

/* push_front: inserts the given item in front of the List */
Bool push_front(List *hptr, int item)
{
    node *temp;

    temp = malloc(sizeof(node));
    if (temp == NULL)
        return 0;

    temp -> data = item;
    temp -> next = *hptr;

    *hptr = temp;
    return 1;
}

/* push_back: inserts the given item in the end of List */
Bool push_back(List *hptr, int item)
{
    node *new_node, *temp;

    new_node = malloc(sizeof(node));
    if (new_node == NULL)
        return 0;
    new_node -> data = item;
    new_node -> next = NULL;

    if (is_empty(*hptr))    // empty List
        *hptr = new_node;
    else {
        temp = *hptr;
        while (temp->next != NULL)
            temp = temp->next;
        temp -> next = new_node;
    }

    return 1;
}

/* pop_front: pops the first element and returns its data */
int pop_front(List *hptr)
{
    if (is_empty(*hptr)) {
        printf("Empty List\n");
        return 0;
    }

    else {
        node *temp = *hptr;
        int data;

        data = (*hptr)->data;
        *hptr = (*hptr)->next;
        free(temp);
        return data;
    }
}

/* pop_back: pops the last element and returns its data */
int pop_back(List *hptr)
{
    node *prev, *temp = *hptr;
    int data;

    if (is_empty(*hptr)) {
        printf("Empty List\n");
        return 0;
    }

    else if ((*hptr)->next == NULL) {
        data = temp->data;
        *hptr = NULL;
        free(temp);
        return data;
    }

    else {
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        data = temp->data;
        prev->next = NULL;
        free(temp);
        return data;
    }
}

/* delete_item: deletes the first node
                with data equal to the given item */ 
Bool delete_item(List *hptr, int item)
{
    node *temp, *prev;
    temp = *hptr;

    /* data found at head */
    if (temp != NULL && temp->data == item) {
        *hptr = temp->next;
        free(temp);
        return 1;
    }

    while (temp != NULL && temp->data != item) {
        prev = temp;
        temp = temp -> next;
    }

    /* item not found */
    if (temp == NULL)
        return 0;
    /* item found */
    else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
    }
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef enum bool {FALSE, TRUE} bool;

bool is_empty(node *head);
void print_list(node *head);
node *search_item(node *head, int item);
bool push_front(node **hptr, int item);
bool push_back(node **hptr, int item);
int pop_front(node **hptr);
int pop_back(node **hptr);
bool delete_item(node **hptr, int item);

node *head = NULL;

/* is_empty: checks if the list is empty*/
bool is_empty(node *head)
{
    return head == NULL;
}

/* print_list: prints all the items of the list */
void print_list(node *head)
{
    node *temp = head;

    if (is_empty(head)) {
        printf("Empty list");
    }

    while (temp != NULL) {
        printf("%d ",temp->data);
        temp = temp -> next;   
    }
    printf("\n");
}

/* search_item: returns the pointer to the node
                if the given item is in the list */
node *search_item(node *head, int item)
{
    node *temp = head;

    while (temp != NULL && temp->data != item)
        temp = temp -> next;

    return temp;
}

/* push_front: inserts the given item in front of the list */
bool push_front(node **hptr, int item)
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

/* push_back: inserts the given item in the end of list */
bool push_back(node **hptr, int item)
{
    node *new_node, *temp;

    new_node = malloc(sizeof(node));
    if (new_node == NULL)
        return 0;
    new_node -> data = item;
    new_node -> next = NULL;

    if (is_empty(*hptr))    // empty list
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
int pop_front(node **hptr)
{
    if (is_empty(*hptr)) {
        printf("Empty list\n");
        return -1;
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
int pop_back(node **hptr)
{
    node *prev, *temp = *hptr;
    int data;

    if (is_empty(*hptr)) {
        printf("Empty list\n");
        return -1;
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
bool delete_item(node **hptr, int item)
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

    /* data not found */
    if (temp == NULL)
        return 0;
    /* data found */
    else {
        prev -> next = temp -> next;
        free(temp);
        return 1;
    }
}
#include <stdio.h>
#include "linked_list.c"

Bool push(int item);
Bool pop(void);


typedef List Stack;
Stack stack=NULL;

Bool push(int item)
{
    push_front(&stack, item);
}

Bool pop(void)
{
    pop_front(&stack);
}
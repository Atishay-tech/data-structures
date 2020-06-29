#include <stdio.h>
#include "linked_list.c"

Bool enque(int item);
Bool deque(void);


typedef List Queue;
Queue queue=NULL;

Bool enque(int item)
{
    push_front(&queue, item);
}

Bool deque(void)
{
    pop_back(&queue);
}
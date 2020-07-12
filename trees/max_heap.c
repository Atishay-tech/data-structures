/* An array based implementation of a binary max-heap
 * Initaialize every new heap as follows: 
 *        Heap heap_name = Heap();       */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024   // maximum number of elements in heap

typedef int Element;
typedef struct {
    Element (*hptr)[MAX_SIZE];
    int size;   // number of elements in heap
} Heap;

#define Heap() {NULL, 0}                // for initializing new heaps
#define elements(heap) (*(heap).hptr)
#define parent(i) ((i-1)/2)
#define left_child(i) ((i)*2 + 1)
#define right_child(i) ((i)*2 + 2)


Element max(Heap);
int size(Heap);
Heap insert(Heap, Element value);
Heap extract_max(Heap);


int main()
{
    void test(void);
    test();

    return 0;
}

/* max: returns the maximum element of the heap */
Element max(Heap heap)
{
    return elements(heap)[0];
}

/* size: returns the size of heap */
int size(Heap heap)
{
    return heap.size;
}

/* extract_max: removes the max element from heap and
                returns the modified heap */
Heap extract_max(Heap heap)
{

}

/* insert: inserts the given element into eh */
Heap insert(Heap heap, Element value)
{
    if (heap.hptr == NULL)
        heap.hptr = malloc(MAX_SIZE * sizeof(Element));

    if (heap.size < MAX_SIZE) {
        elements(heap)[heap.size] = value;
        heap.size += 1;
    }
    else {
        printf("insert Error: " "Heap size limit reached");
    }

    return heap;
}


/* test: testing function used to test the above functions */
void test(void)
{
    Heap heap = Heap();

    heap = insert(heap, 7);
    printf("%d %d\n", size(heap), max(heap));
}
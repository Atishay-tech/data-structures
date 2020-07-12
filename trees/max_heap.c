/* An array based implementation of a binary max-heap
 * Initaialize every new heap as follows: 
 *        Heap heap_name = Heap();       */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024   // maximum number of elements in heap

typedef int Element;
typedef struct {
    Element *elements;  // pointer to the elements of heap
    int size;           // number of elements in heap
} Heap;

#define Heap() {NULL, 0}        // for initializing new heaps
#define parent(i) ((i-1)/2)
#define left_child(i) ((i)*2 + 1)
#define right_child(i) ((i)*2 + 2)


Element max(Heap);
int size(Heap);
Heap insert(Heap, Element value);
Heap extract_max(Heap);
void print_heap(Heap);
void heap_sort(Element array[], int size);
Heap build_heap(Element array[], int size);

/*
int main()
{
    void test(void);
    test();

    return 0;
}*/

/* max: returns the maximum element of the heap */
Element max(Heap heap)
{
    if (heap.size == 0)
        printf("max Error: " "Given heap is empty");
    else
        return heap.elements[0];
}

/* size: returns the size of heap */
int size(Heap heap)
{
    return heap.size;
}

/* insert: inserts the given element into eh */
Heap insert(Heap heap, Element value)
{
    void sift_up(Heap, int indx);

    if (heap.elements == NULL)
        heap.elements = malloc(MAX_SIZE * sizeof(Element));

    if (heap.size < MAX_SIZE) {
        heap.elements[heap.size] = value;
        heap.size += 1;
        sift_up(heap, heap.size-1);
    }
    else {
        printf("insert Error: " "Heap size limit reached");
    }

    return heap;
}

/* sift_up: swaps the given node with its parent node
 *          until its value is smaller than or equal to its parent */
void sift_up(Heap heap, int i)
{
    void swap(Element *a, Element *b);

    while (i > 0 && heap.elements[parent(i)] < heap.elements[i]) {
        swap(heap.elements + i, heap.elements + parent(i));
        i = parent(i);
    }
}

/* swap: swaps the values of elements at given addresses */
void swap(Element *a, Element *b)
{
    Element temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/* extract_max: removes the max element from heap and
 *              returns the modified heap */
Heap extract_max(Heap heap)
{
    void sift_down(Heap, int indx);

    heap.elements[0] = heap.elements[heap.size-1];
    sift_down(heap, 0);
    heap.size -= 1;

    return heap;
}

/* sift_down: swaps the given node with its larger child node recursively
 *            until its value is higher than or equal to both of its children */
void sift_down(Heap heap, int i)
{
    void swap(Element *a, Element *b);

    int max = i;
    if (heap.size > left_child(i)
            && heap.elements[left_child(i)] > heap.elements[max])
        max = left_child(i);
    if (heap.size > right_child(i)
            && heap.elements[right_child(i)] > heap.elements[max])
        max = right_child(i);

    if (max != i) {
        swap(heap.elements + i, heap.elements + max);
        i = max;
        sift_down(heap, i);
    }
}

/* print_tree: breadth-first traversal of the heap */
void print_heap(Heap heap)
{
    printf("Breadth-first traversal of heap: \n");
    for(int i = 0; i < heap.size; i++)
        printf("%d ", heap.elements[i]);
    printf("\n");
}

/* build_heap: constructs and returns a max heap from the given array */
Heap build_heap(Element *arr, int size)
{
    Heap heap = {arr, size};

    for (int i = 1; i < heap.size; i++)
        sift_up(heap, i);
    
    return heap;
}

/* heap_sort: in-place sorting of the given array */
void heap_sort(Element *arr, int size)
{
    void swap(Element *, Element *);
    Heap build_heap(Element *arr, int size);
    Heap extract_max(Heap);
    Element max(Heap);

    Heap heap = build_heap(arr, size);

    for(int i = size-1; i > 0; i--) {
        Element highest = max(heap);
        heap = extract_max(heap);
        arr[i] = highest;
    }
}


/* test: testing function I used to test the above functions 
void test(void)
{
    Heap heap = Heap();

    printf("%d %d\n", size(heap), max(heap));
    heap = insert(heap, 7);
    heap = insert(heap, 9);
    heap = insert(heap, 10);
    heap = insert(heap, 1);
    printf("%d %d\n", size(heap), max(heap));
    print_heap(heap);
    heap = extract_max(heap);
    heap = extract_max(heap);
    print_heap(heap);

    Element arr[] = {10, 4, 28, 2, 2, 7, 1};
    int size = 6;
    build_heap(arr, size);
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    heap_sort(arr, size);
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
} */
/* Dynamic implementation of Arrays
* 
* Any new array can be initailized as: 
*       Array arr = Array();
*/

#include <stdio.h>
#include <stdlib.h>

#define Array() {NULL, 0, 0}

typedef struct {
    int (*array)[];
    int size;
    int capacity;
} Array;


int get(Array, int index);
Array set(Array, int index, int value);
Array push_back(Array, int value);
Array remove_i(Array, int index);
int size(Array);
void print_array(Array);

/*
int main()
{
    void test(void);
    test();

    return 0;
}*/


/* set: sets the value at given index of the array to val */ 
Array set(Array arr, int i, int val)
{
    if (i>=0 && i<arr.size) {
        (*arr.array)[i] = val;
        return arr;
    }
    else {
        printf("set Error: Array index out of range");
        return arr;
    }
}

/* get: returns the value at given index position */
int get(Array arr, int i)
{
    if (i>=0 && i<arr.size)
        return (*arr.array)[i];
    else
        printf("get Error: Array index out of range");
}

/* push_back: pushes a new value into the array */
Array push_back(Array arr, int val)
{

    // Adding first element to the array
    if(arr.capacity == 0) {
        arr.capacity = 1;
        arr.array = malloc(sizeof(int));
    }
    // If capacity increase is needed
    else if (arr.capacity && arr.capacity == arr.size) {
        int (*temp)[] = malloc(2*arr.capacity*sizeof(int));

        if (temp) { // Enough space available in system buffer
            for (int i=0; i<arr.size; i++)
                (*temp)[i] = (*arr.array)[i];
            free(arr.array);
            arr.array = temp;
            arr.capacity *= 2;    
        }
        else {  // Program buffer full
            printf("push_back Error: "
                "Enough space not available in buffer");
        }
    }

    (*arr.array)[arr.size] = val;
    arr.size += 1;
    return arr;
}

/* remove_i: removes the element with index i */
Array remove_i(Array arr, int i)
{
    if (i<0 || i>=arr.size) {
        printf("remove_i Error: Index position out of range");
        return arr;
    }

    for(int j=i; j<arr.size; j++)
        (*arr.array)[i] = (*arr.array)[i+1];
    arr.size -= 1;
    return arr;
}

/* size: returns the size of array */
int size(Array arr)
{
    return arr.size;
}

/* print_array: prints the complete array */
void print_array(Array arr)
{
    int get(Array, int i);

    for (int i=0; i<arr.size; i++)
        printf("%d ", get(arr, i));
    printf("\n");
}


/* test: the utility function I used to test the functions
void test(void)
{
    Array arr = Array();
    arr = push_back(arr, 1);
    arr = push_back(arr, 2);
    arr = push_back(arr, 3);
    arr = push_back(arr, 4);
    arr = push_back(arr, 5);
    arr = remove_i(arr, 3);
    arr = set(arr, 3, 6);
    print_array(arr);
    printf("%d\n", get(arr, 3));
}
*/

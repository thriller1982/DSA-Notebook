#ifndef BINARY_HEAP_LIBRARY_H
#define BINARY_HEAP_LIBRARY_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;
const int MinPQSize = 10;

PriorityQueue Initialize(int max_elements);
void Insert(ElementType x, PriorityQueue h);

#endif // BINARY_HEAP_LIBRARY_H
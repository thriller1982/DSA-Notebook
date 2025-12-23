#ifndef BINARY_HEAP_LIBRARY_H
#define BINARY_HEAP_LIBRARY_H

#include <stdbool.h>
struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;
const int MinPQSize = 10;

PriorityQueue Initialize(int max_elements);
void Insert(ElementType x, PriorityQueue h);
ElementType DeleteMin(PriorityQueue h);
void PercolateDown(PriorityQueue h, int i);
PriorityQueue BuildHeap(ElementType *elements, int n);
bool IsFull(PriorityQueue h);
bool IsEmpty(PriorityQueue h);

#endif // BINARY_HEAP_LIBRARY_H
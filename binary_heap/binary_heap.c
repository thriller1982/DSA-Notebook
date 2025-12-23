#include "binary_heap.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdbool.h>

struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};
bool IsFull(PriorityQueue h);

PriorityQueue Initialize(int max_elements) {
    if (max_elements < MinPQSize) {
        Error("Priority queue size is too small");
    }
    PriorityQueue h = malloc(sizeof(struct HeapStruct));
    if (h == NULL) {
        FatalError("Out of space!!!");
    }
    h->elements = malloc((max_elements + 1) * sizeof(ElementType));
    if (h->elements == NULL) {
        FatalError("Out of space!!!");
    }

    h->capacity = max_elements;
    h->size = 0;

    return h;
}

void Insert(ElementType x, PriorityQueue h) {
    if (IsFull(h)) {
        Error("Priority queue is full");
        return;
    }
    int i;
    for (i = ++h->size; h->elements[i / 2] > x; i /= 2) {
        h->elements[i] = h->elements[i / 2];
    }
    h->elements[i] = x;
}

bool IsFull(PriorityQueue h) {
    return h->size == h->capacity;
}
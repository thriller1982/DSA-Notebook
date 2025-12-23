#include "binary_heap.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct HeapStruct {
    int capacity;
    int size;
    ElementType *elements;
};

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
    h->elements[0] = INT_MIN;

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

ElementType DeleteMin(PriorityQueue h) {
    if (IsEmpty(h)) {
        Error("Priority queue is empty");
        return h->elements[0];
    }
    ElementType min_element = h->elements[1];
    ElementType last_element = h->elements[h->size--];

    int i, child;
    for (i = 1; i * 2 <= h->size; i = child) {
        child = i * 2;
        if (child != h->size && h->elements[child] > h->elements[child + 1]) {
            ++child;
        }
        if (h->elements[child] < last_element) {
            h->elements[i] = h->elements[child];
        } else {
            break;
        }
    }
    h->elements[i] = last_element;
    return min_element;
}

void PercolateDown(PriorityQueue h, int i) {
    ElementType down_element = h->elements[i];
    int j, child;
    for (j = i; j * 2 <= h->size; j = child) {
        child = j * 2;
        if (child != h->size && h->elements[child] > h->elements[child + 1]) {
            ++child;
        }
        if (h->elements[child] < down_element) {
            h->elements[j] = h->elements[child];
        } else {
            break;
        }
    }
    h->elements[j] = down_element;
}

PriorityQueue BuildHeap(ElementType *elements, int n) {
    PriorityQueue h = malloc(sizeof(struct HeapStruct));
    if (h == NULL) {
        FatalError("Out of space!!!");
    }
    h->elements = malloc((n + 1) * sizeof(ElementType));
    if (h->elements == NULL) {
        FatalError("Out of space!!!");
    }

    for (int i = 1; i < n + 1; i++) {
        h->elements[i] = elements[i - 1];
    }
    h->size = h->capacity = n;
    h->elements[0] = INT_MIN;

    for (int i = n / 2; i >= 1; --i) {
        PercolateDown(h, i);
    }
    return h;
}

bool IsFull(PriorityQueue h) {
    return h->size == h->capacity;
}

bool IsEmpty(PriorityQueue h) {
    return h->size == 0;
}
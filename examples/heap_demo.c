#include <stdio.h>
#include "binary_heap.h"

int main(void) {
    PriorityQueue h = Initialize(20);
    int values[] = {20, 5, 15, 22, 9, 1};
    int n = (int)(sizeof(values) / sizeof(values[0]));

    for (int i = 0; i < n; ++i) {
        Insert(values[i], h);
    }

    printf("DeleteMin output: ");
    while (!IsEmpty(h)) {
        printf("%d ", DeleteMin(h));
    }
    printf("\n");

    return 0;
}

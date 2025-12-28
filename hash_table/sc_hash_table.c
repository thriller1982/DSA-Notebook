#include "sc_hash_table.h"

#include "fatal.h"
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    ElementType element;
    Position next;
};

typedef Position List;

struct HashTbl {
    int table_size;
    List* the_lists;
};
static bool IsPrime(int n);
static int NextPrime(int n);
HashTable InitializeTable(int table_size) {
    if (table_size < MinTableSize) {
        Error("Table size too small!");
        return NULL;
    }
    HashTable h = malloc(sizeof(struct HashTbl));
    if (h == NULL) {
        FatalError("Out of space!!!");
    }
    h->table_size = NextPrime(table_size);
    h->the_lists = malloc(h->table_size * sizeof(List));
    for (int i = 0; i < h->table_size; ++i) {
        h->the_lists[i] = malloc(sizeof(struct ListNode));
        if (h->the_lists[i] == NULL) {
            FatalError("Out of space!!!");
        } else {
            h->the_lists[i]->next = NULL;
        }
    }
    return h;
}

int IntHash(int n, int table_size) {
    return (n % table_size + table_size) % table_size;
}

Position Find(ElementType key, HashTable h) {
    List l = h->the_lists[IntHash(key, h->table_size)];
    Position p = l->next;
    while (p != NULL && p->element != key) {
        p = p->next;
    }
    return p;
}

void Insert(ElementType key, HashTable h) {
    Position pos = Find(key, h);
    if (pos == NULL) {
        Position new_cell = malloc(sizeof(struct ListNode));
        if (new_cell == NULL) {
            FatalError("Out of space!!!");
        } else {
            List l = h->the_lists[IntHash(key, h->table_size)];
            new_cell->next = l->next;
            new_cell->element = key;
            l->next = new_cell;
        }
    }
}

void Delete(ElementType key, HashTable h) {
    List l = h->the_lists[IntHash(key, h->table_size)];
    Position pos = l->next;
    while (pos ->next != NULL && pos->next->element != key) {
        pos = pos->next;
    }
    if (pos->next) {
        Position temp_cell = pos->next;
        pos->next = pos->next->next;
        free(temp_cell);
    }
}

unsigned StringHash(char* ch, int table_size) {
    unsigned sum = 0;
    while (*ch != '\0') {
        sum = (sum + *(ch++)) * 31;
    }
    return sum % table_size;
}

static bool IsPrime(int n) {
    if (n == 2) {
        return true;
    }
    if (n < 2 || n % 2 == 0) {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

static int NextPrime(int n) {
    for (int i = n + 1; ; ++i) {
        if (IsPrime(i)) {
            return i;
        }
    }
}
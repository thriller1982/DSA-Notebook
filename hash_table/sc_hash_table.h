#ifndef HASH_TABLE_SC_HASH_TABLE_H
#define HASH_TABLE_SC_HASH_TABLE_H

#define MinTableSize 3
typedef int ElementType;
struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;

HashTable InitializeTable(int table_size);
int IntHash(int n, int table_size);
unsigned StringHash(char* ch, int table_size);
Position Find(ElementType key, HashTable h);
void Insert(ElementType key, HashTable h);
void Delete(ElementType key, HashTable h);

#endif //HASH_TABLE_SC_HASH_TABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *findName(char lastName[], entry *hashTable)
{
    int32_t value = hashFunc(lastName);
    entry *iter = &hashTable[value];

    while (strcmp(iter->lastName, lastName)) {
        iter = iter->pColNext;
        if (iter == NULL)  return iter;
    }
    return iter;
}

entry *append(char lastName[], entry *hashTable)
{
    int32_t value = hashFunc(lastName);
    entry *iter = hashTable[value].lastEle;


    iter->pColNext = (entry *) malloc(sizeof(entry));
    hashTable[value].lastEle = iter->pColNext;
    strncpy(iter->pColNext->lastName, lastName, 16);

    return hashTable;
}

u_int32_t hashFunc(char lastName[])
{
    /* using dbj2 hash function */
    u_int32_t hash = 5381;
    int32_t c;

    while (c = *lastName++)
        hash = ((hash << 5) + hash) + c;

    return hash%40009;
}


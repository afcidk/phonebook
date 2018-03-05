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

int32_t hashFunc(char lastName[])
{
    /* using Rabin-Karp hash function */
    int32_t q = 40009;
    int64_t hashValue = 0;
    int32_t len = strlen(lastName);
    int64_t p = 1;

    for (int i=0, j=len-1; i<len; ++i, --j) {
        hashValue += (lastName[j]*p) % q;
        p *= 17;
        p %= q;
        hashValue %= q;
    }
    return hashValue;
}


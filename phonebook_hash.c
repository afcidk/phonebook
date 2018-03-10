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
    entry *iter = &hashTable[value];

    iter->pColNext = (entry *) malloc(sizeof(entry));
    strncpy(iter->pColNext->lastName, lastName, 16);

    return hashTable;
}

u_int32_t hashFunc(char lastName[])
{
    /* using dbj2 hash function */
    u_int32_t hash = 5381;
    int32_t c;

    while ((c = *lastName++))
        hash = ((hash << 5) + hash) + c;

    return hash%40009;

    /* using rolling hash function *optimized* */
    /* int32_t q = 40009;
     * u_int32_t hashValue = 0;
     * int32_t c;
     * int64_t p=1;
     *
     * while (c = *lastName++) {
     *     hashValue += (c*p)%q;
     *     p = p<<4 + p;
     *   p %= q;
     *   hashValue %= q;
     *}
     *return hashValue;
    */
}


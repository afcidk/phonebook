#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_trie.h"

entry *findName(char lastName[], entry *pHead)
{
    char c;
    entry *iter = pHead;
    while ((c = *lastName++)) {
        int ind = 0;
        if (islower(c)) ind = c-'a'+26;
        else if (isupper(c)) ind = c-'A';
        else printf("invalid name");

        if (iter->nch[ind] != NULL) iter = iter->nch[ind];
        else {
            printf("cannot find name");
            return NULL;
        }
    }
    return pHead;
}

entry *append(char lastName[], entry *pHead)
{
    char c;
    entry *iter = pHead;
    while ((c = *lastName++)) {
        int ind = 0;
        if (islower(c)) ind = c-'a'+26;
        else if (isupper(c)) ind = c-'A';
        else printf("invalid name");

        if (iter->nch[ind] == NULL) {
            iter->nch[ind] = (entry *) malloc(sizeof(entry));
            // TODO: malloc space to store data
        }
        iter = iter->nch[ind];
    }
    return pHead;
}

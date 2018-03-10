#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define TRIE 1

typedef struct __PHONE_BOOK_ENTRY {
    struct __PHONE_BOOK_ENTRY *nch[52];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} entry;

entry *findName(char lastName[], entry *pHead);
entry *append(char lastName[], entry *pHead);

#endif

#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define HASH 1
typedef struct __OTHER_PHONE_BOOK_ENTRY {

    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} phonebookData;

typedef struct __PHONE_BOOK_ENTRY {
    int32_t hashValue;
    struct __PHONE_BOOK_ENTRY *pNext;
    char lastName[MAX_LAST_NAME_SIZE];
    phonebookData *pData;

    // if collided, point to next lastName
    struct __PHONE_BOOK_ENTRY *pColNext;
    struct __PHONE_BOOK_ENTRY *lastEle;
} entry;


entry *findName(char lastName[], entry *hashTable);
entry *append(char lastName[], entry *hashTable);
u_int32_t hashFunc(char lastName[]);

#endif

#ifndef __LINKEDLIST_H__
# define __LINKEDLIST_H__

# include <stdlib.h>
# include <stdio.h>

typedef struct LinkedList {
	char* word;
	struct LinkedList* next;
} s_LinkedList;

s_LinkedList* newElement(char* word, s_LinkedList* root);
void freeDictionnary(s_LinkedList* ll);
void sortDictionnary(s_LinkedList* current);

#endif // !__LINKEDLIST_H__

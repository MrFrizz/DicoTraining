#ifndef __DICO_H__
# define __DICO_H__

# include <stdlib.h>
# include <stdio.h>

#include "linkedList.h"

const int createDico(const char* fileName);
const int removeDico(const char* fileName);
const int loadDico(const char* fileName, s_LinkedList* root);

#endif // !__DICO_H__

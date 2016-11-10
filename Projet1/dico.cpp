#include "dico.h"

#include <string.h>

const int createDico(const char* fileName) {

	FILE* dictionnary = fopen(fileName, "w");
	if (dictionnary != NULL) {

		printf("The dictionnary has been well created.");
		return 1;
	}
	else {

		printf("The creation of the dictionnary failed.");
		return 0;
	}
}

const int removeDico(const char* fileName) {

	remove(fileName);

	return 1;
}

/**
* \fn const int loadDico(const char* fileName)
* \brief Tokenizer function
*
* \param Name of the file : dictionnary
* \return 0 if no error, 1 if error
*/
const int loadDico(const char* fileName, s_LinkedList* root) {
	char* word = (char*)malloc(sizeof(char) * 1024);
	s_LinkedList* wordToList = NULL;
	int i = 0;
	char check = 0;
	int backn = 0;

	FILE* dictionnary = fopen(fileName, "r");

	if (dictionnary != NULL) {

		// Split text
		while (check != EOF) {
			check = fgetc(dictionnary);

			// take each letter of a word and display it	
			if ((check >= 65 && check <= 90) || (check >= 97 && check <= 122) || (check == 45)) {
				word[i] = check;
				i++;

				backn = 0;

				continue;
			}

			// if it's anything else than a letter min/maj or a dash, make a backline once
			if (backn != 1) {
				word[i] = '\0';
				root = newElement(word, root);
				free(word);
				word = (char*)malloc(sizeof(char) * 1024);

				backn = 1;
				i = 0;
			}

		}
	}
	else {
		printf("Openning forbidden");

		return 0;
	}

	return 1;

}

/**
* \fn s_LinkedList* newElement(char* wordToList)
* \brief Create a linkedlist with the struct s_LinkedList
*
* \param The word that need to be Linkeded
* \return The s_LinkedList
*/
s_LinkedList* newElement(char* wordToList, s_LinkedList* root) {
	// Init
	s_LinkedList* head = root;
	root  = (s_LinkedList*)malloc(sizeof(s_LinkedList));
	root->word = (char*)calloc(strlen(wordToList), sizeof(char) * strlen(wordToList));
	strcpy(root->word, wordToList);
	root->next = head;

	s_LinkedList* tmp = root;
	while (tmp != NULL) {
		printf("%s ", tmp->word);
		tmp = tmp->next;
	}
	printf("\n");

	return root;
}

/**
* \fn void freeDictionnary(s_LinkedList* ll)
* \brief Free all the malloc
*
* \param The linkedList from where you want to free to the end
*/
void freeDictionnary(s_LinkedList* ll) {
	
	if (ll->next) {
		freeDictionnary(ll->next);
	}
	free(ll);
}

/**
* \fn 
* \brief Create a linkedlist with the struct s_LinkedList
*
* \param The word that need to be Linkeded
* \return The s_LinkedList
*/

void sortDictionnary(s_LinkedList* current) {


}
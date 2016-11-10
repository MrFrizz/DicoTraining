#include "dico.h"

int main(int argc, char* argv[])
{
	s_LinkedList* root = NULL;

	loadDico("banana.txt", root);

	scanf("");
	// success = createDico("banana.txt");
	// removeDico("banana.txt");

	return 0;
}
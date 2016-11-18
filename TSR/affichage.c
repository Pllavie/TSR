#include "include/affichage.h"

void tab(int profondeur)
{
	int i;
	if (profondeur<0)
	{
		perror("Error dans my tab : Profondeur négative");
		exit(0);
	}
	for(i=0;i<profondeur;i++)
	{
		printf("	");
	}
}
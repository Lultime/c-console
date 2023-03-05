#include<iostream>
#include <stdlib.h>
using namespace std;
void Arbre(char *word, int n, int lg, char *solution, int taille_solution)	// Fonction recursive
{
	char *comb;
	int i,j,k,m;

	if (lg!=0)
	{
		comb = (char *)malloc((lg)*sizeof(char)+1);		//Voir plus bas

		taille_solution++;		// On est descendu d'un étage dans l'arbre => taille de la solution +1
		for (i=0;i<lg;i++)		// Pour chaque lettre du nouveau mot on réalise autant d'arbre pour l'étage suivant
		{
			solution[n]=word[i];	// On ajoute la nouvelle lettre à la fin de la solution (n = étage)
			for (m=0;m<(taille_solution);m++) cout << solution[m];	// Affiche la solution en cours
			cout.flush() << "	";

			k=0;				// ICI on définit la nouvelle combinaison COMB avec les lettres restantes
			for (j=0;j<lg;j++)
			{
				if (j!=i)
				{
					comb[k] = word[j];	// Donc comb prend toutes les lettres restantes
					k++;
				}
			}

			Arbre(comb, n+1, lg-1, solution, taille_solution);	// Puis on descend d'un étage dans l'arbre en reinjectant le nouveau comb
		}
	}
	else taille_solution--;	// On remonte d'un étage dans l'arbre
}

void main()
{
	char *word;
	char *solution;
	char TEMP[25]={"########################"};

	int n_arbre=1;
	int taille_solution=0;
	int long_anagram;

	cout << "BIENVENU DANS ANAGRAMME\n\n"; cout << "Entrer l'anagramme : ";
	cin >> TEMP;

	for (long_anagram=0;TEMP[long_anagram]!='#';long_anagram++);	// Ici, on compte juste le nombre de caractères
	word = (char *)malloc(long_anagram*sizeof(char)+1);
	solution = (char *)malloc(long_anagram*sizeof(char)+1);			// Là ou seront stockées les différentes solutions
	for (int m=0;m<long_anagram;m++) word[m]=TEMP[m];

	cout << "RECHERCHE DES ANAGRAMMES DE " << word << "\n\n";

	Arbre(word,0,long_anagram-1,solution,taille_solution);			// On rentre dans le premier étage de l'arbre

	if (word) free(word);
	if (solution) free(solution);
}
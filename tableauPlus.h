/*
 * tableauPlus.h
 * Auteur: Patrick Lainesse
 * Cours: IFT1166 - A19 - Mardi 16h30
 *
 * Fichier d'en-tete d'un programme qui resoud le depassement de capacite des tableaux pour
 * une classe cree par template
 */

#include <iostream>

using namespace std;

template <class Type> class tableauPlus
{
private:
	int indiceMin = 0;	// valeur par défaut
	int indiceMax;
	Type* tableau;

public:
	tableauPlus(int max);
	tableauPlus(int min, int max);
	tableauPlus(const tableauPlus<Type>& t1);
	~tableauPlus();		// destructeur pour le tableau dynamique
	Type& operator [] (int i);
	bool depassement(int i);
	template<class Type, class U> friend bool operator == (tableauPlus<Type>& gauche, tableauPlus<U>& droite);
	template<class Type, class U> friend bool operator != (tableauPlus<Type>& gauche, tableauPlus<U>& droite);
};

/* EXECUTION
On declare les tableaux des instructions de l'exercice.
On affecte, puis on essaie d'acceder a des indices de chaque tableau avec l'operateur [].
tabInt[1]: 4
tabDouble[2]: 5.5
tabDouble[12] (non initialise): -6.27744e+66
tabChar[-1]: b

On declare un nouveau tableau identique a tabInt pour le comparer.
comparaison == tabInt retourne: vrai!

On compare comparaison avec tabChar a l'aide de !=
comparaison != tabChar retourne: vrai!

Finalement, on essaie d'affecter et d'acceder a des indices inexistants dans le tableau.ATTENTION! Cela mettra (volontairement) fin au programme.
Erreur, depassement de la capacite du tableau

C:\Users\admin\Desktop\1166\tp3\TERMINE\TERMINE\Debug\TERMINE.exe (process 19604) exited with code 1.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/
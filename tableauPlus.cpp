/*
 * tableauPlus.cpp
 * Auteur: Patrick Lainesse
 * Cours: IFT1166 - A19 - Mardi 16h30
 *
 * Programme qui resoud le depassement de capacite des tableaux pour
 * une classe cree par template
 */

#include "tableauPlus.h"

template<class Type> tableauPlus<Type>::tableauPlus(int max)
{
	indiceMax = max;
	tableau = new Type[max];
}

template<class Type> tableauPlus<Type>::tableauPlus(int min, int max)
{
	indiceMin = min;
	indiceMax = max;
	tableau = new Type[max - min];
}

template<class Type> tableauPlus<Type>::tableauPlus(const tableauPlus<Type>& t1)
{
	indiceMin = t1.indiceMin;
	indiceMax = t1.indiceMax;

	tableau = new Type[indiceMax - indiceMin];
	for (int i = indiceMin; i < indiceMax; i++)
		tableau[i] = t1.tableau[i];
}

template<class Type> tableauPlus<Type>::~tableauPlus()
{
	delete[] tableau;
}

template<class Type> Type& tableauPlus<Type>::operator [] (int i)
{
	if (!depassement(i))
		return tableau[i - indiceMin];
	else
		exit(EXIT_FAILURE);
}

template<class Type> bool tableauPlus<Type>::depassement(int i)
{
	if (i < indiceMin || i >= indiceMax)
	{
		cout << "Erreur, depassement de la capacite du tableau\n";
		return true;
	}
	else
		return false;
}

template<class Type, class U> bool operator == (tableauPlus<Type>& gauche, tableauPlus<U>& droite)
{
	if (gauche.indiceMin == droite.indiceMin && gauche.indiceMax == droite.indiceMax && typeid(gauche.tableau) == typeid(droite.tableau))
	{
		for (int i = gauche.indiceMin; i < gauche.indiceMax; i++)
		{
			if (gauche.tableau[i] != droite.tableau[i])
				return false;
		}
		return true;
	}
	else return false;
}

template<class Type, class U> bool operator != (tableauPlus<Type>& gauche, tableauPlus<U>& droite)
{
	if (gauche.indiceMin == droite.indiceMin && gauche.indiceMax == droite.indiceMax && typeid(gauche.tableau) == typeid(droite.tableau))
	{
		for (int i = gauche.indiceMin; i < gauche.indiceMax; i++)
		{
			if (gauche.tableau[i] == droite.tableau[i])
				return false;
		}
		return false;
	}
	else return true;
}

int main()
{

	cout << "On declare les tableaux des instructions de l'exercice.\n";
	tableauPlus<int> tabInt(5);
	tableauPlus<double> tabDouble(2, 13);
	tableauPlus<char> tabChar(-5, 9);
	
	cout << "On affecte, puis on essaie d'acceder a des indices de chaque tableau avec l'operateur [].\n";
	tabInt[1] = 4;
	cout << "tabInt[1]: " << tabInt[1] << endl;

	tabDouble[2] = 5.5;
	cout << "tabDouble[2]: " << tabDouble[2] << endl;
	cout << "tabDouble[12] (non initialise): " << tabDouble[12] << endl;

	tabChar[-1] = 'b';
	cout << "tabChar[-1]: " << tabChar[-1] << endl;

	cout << "\nOn declare un nouveau tableau identique a tabInt pour le comparer.\n";
	tableauPlus<int> comparaison(5);
	comparaison[1] = 4;

	if (comparaison == tabInt)
		cout << "comparaison == tabInt retourne: vrai!\n";
	else
		cout << "comparaison == tabInt retourne: faux!.\n";

	cout << "\nOn compare comparaison avec tabChar a l'aide de !=\n";
	if (comparaison != tabChar)
		cout << "comparaison != tabChar retourne: vrai!\n";
	else
		cout << "comparaison != tabChar retourne: faux!\n";

	cout << "\nFinalement, on essaie d'affecter et d'acceder a des indices inexistants dans le tableau."
		<< "ATTENTION! Cela mettra (volontairement) fin au programme.\n";
	tabInt[-1] = 2;
	cout << "tabInt[-1]: " << tabInt[-1] << endl;
		
	return 0;
}
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
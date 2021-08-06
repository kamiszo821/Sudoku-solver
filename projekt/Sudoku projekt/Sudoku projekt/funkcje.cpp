/** @file */
#include "funkcje.h"
using namespace std;
/**Funkcja szukaj¹ca nieprzypisanego pola
* @param tab tablica sudoku
* @param rzad numer rzedu
* @param kol numer kolumny
* @return Funkcja zwraca wartosc true gdy zostanie znalezione nieprzypisane miejsce
*/

bool wolne_pole(int tab[N][N], int &rzad, int &kol)
{
	for (rzad = 0; rzad < N; rzad++)
		for (kol = 0; kol < N; kol++)
			if (tab[rzad][kol] == 0)
				return true;
	return false;
}


/**Funkcja rozwiazuj¹ca sudoku:sprawdzanie liczb oraz warunkow zgodnych z regulami gry sudoku
* @param tab tablica sudoku
* @return Funkcja zwraca wartosc true gdy zagadka sudoku zostanie rozwiazana
*/


bool rozwiaz_sudoku(int tab[N][N])
{
	int rzad, kol;
	if (!wolne_pole(tab, rzad, kol))
		return true;
	for (int liczba = 1; liczba <= 9; liczba++)
	{
		if (warunki(tab, rzad, kol, liczba)) //jesli warunki=0 to od nowa
		{
			tab[rzad][kol] = liczba;
			if (rozwiaz_sudoku(tab)) //czekam az sie skonczy poprzedni
				return true;
			tab[rzad][kol] = 0; //zeruje liczbe poprzednia
		}
	}
	return false; //backtracking
}

/**Funkcja sprawdzajaca czy w rzedzie nie nast¹pilo powtorzenie liczby
* @param tab tablica sudoku
* @param rzad numer rzedu
* param liczba sprawdzana liczba
* @return Funkcja zwraca wartosc false gdy nie zostanie powtorzona liczba w danym rzedzie
*/

bool sprawdz_rzad(int tab[N][N],int rzad,int liczba)
{
	for (int kol = 0; kol < N; kol++)
			if (tab[rzad][kol] == liczba)
			return true;
	return false;
}


/** Funkcja sprawdzajaca czy w kolumnie nie nastapilo powtorzenie liczby
* @param tab tablica sudoku
* @param kol numer kolumny
* @param liczba sprawdzana liczba
* @return Funkcja zwraca wartosc false gdy nie zostanie powtorzona liczba w danym rzdzie
*/

bool sprawdz_kol(int tab[N][N], int kol, int liczba)
{
	for (int rzad = 0; rzad < N; rzad++)
		if (tab[rzad][kol] == liczba)
		return true;
	return false;
}

/**Funkcja sprawdzajaca czy w kostce 3x3 nie nast¹pilo powtorzenie liczby
* @param tab tablica sudoku
* @param adr1rzad wspolrzedne rzedu dla pierwszego punktu w kostce
* @param adr1kol wspolrzedne kolumny dla pierwszego punktu w kostce
* @param liczba sprawdzana liczba
* @return Funkcja zwraca wartosc false gdy nie zostanie powtorzona liczba w kostce 3x3
*/

bool sprawdz_kostke (int tab[N][N],int adr1rzad,int adr1kol,int liczba)
{
	for (int rzad = 0; rzad < 3; rzad++)
		for (int kol=0; kol< 3; kol++)
			if(tab[rzad+adr1rzad][kol+adr1kol]==liczba)
			return true;
	return false;
}

/**Funkcja sprawdzajaca wszystkie warunki poprawnosci sudoku
* @param tab tablica sudoku
* @param rzad numer kolumny
* @param kol numer rzedu
* @param liczba sprawdzana liczba
* @return Funkcja zwraca true gdy wszystkie warunki s¹ spelnione, a false gdy nie
*/

bool warunki(int tab[N][N], int rzad, int kol, int liczba) 
 {
	return !sprawdz_rzad(tab, rzad, liczba) && !sprawdz_kol(tab, kol, liczba) && !sprawdz_kostke(tab,rzad-rzad%3,kol-kol%3,liczba);
}







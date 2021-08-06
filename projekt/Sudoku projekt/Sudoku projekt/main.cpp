/** @file */
#include <iostream>
#include <sstream>
#include <fstream>
#include "przelaczniki.h"
#include "funkcje.h"
using namespace std;
const int M = 9;
/** Funkcja main programu
*@param argc liczba parametrow programu wpisanych do konsoli
*@param argv tablica parametow z konsoli
*/
int main(int argc, char* argv[])
{
	vector<string> parametry;
	for (int i = 1; i < argc; ++i)
	{
		parametry.push_back(argv[i]);
	}

	Parametry p;
	if (Para(p, parametry))
	{
		int tab[M][M];
		ifstream plikwe(p.in);
		if (plikwe.is_open())
		{
			string line;
			int rzad = 0;
			while (getline(plikwe, line))
			{
				stringstream ss;
				ss << line;
				char temp;
				for (int k = 0; k < M; k++)
				{
					ss >> temp;
					if (temp == 'X')
						tab[rzad][k] = 0;
					else if ((int)temp > '0' && (int)temp <= '9') 
						tab[rzad][k] = (int)temp - 48;
					else
					{
						cout << "Niepoprawne dane wejscia";
						return -1;
					}
				}
				rzad++; //numery rzedow
			}
			if (rozwiaz_sudoku(tab) == true) 
			{
				ofstream plikwy(p.out); //drukowanie do pliku wyjsciowego
				if (plikwy.is_open())
				{
					for (int i = 0; i < M; i++)
					{
						for (int k = 0; k < M; k++)
						{
							plikwy << tab[i][k] << " ";
						}
						plikwy << endl;

					}
				}
			}
			else
				cout << "brak rozwiazan";
		}

		else
			cout << "Nie ma pliku";
	}
	else
	{
		cout << "bledne parametry\n";
		cout << "uzyj: -i <input> -o <output>\n";
		return 1;
	}
	
}
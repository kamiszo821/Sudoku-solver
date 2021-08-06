/** @file */
#include "przelaczniki.h"
using namespace std;
const int   M= 9;
/**Funkcja odpowiadajaca za parametry programu
* @param p struktura zawierajaca wejœcie i wyjscie
* @param params wektor zawierajacy dane z konsoli
* @return funkcja zwraca wartosc true gdy podane zostana poprawne parametry
*/
bool Para(Parametry& p, const vector<string>& params)
{
	if (params.size() > 0)
		for (int i = 0; i < params.size() - 1; ++i)
			if (params[i] == "-i")
				p.in = params[++i]; //miejsce gdzie nazwa pliku zrodlowego 
			else if (params[i] == "-o")
				p.out = params[++i]; //nazwa pliku wyjsciowego 

	return p.in != "" && p.out != "";
}


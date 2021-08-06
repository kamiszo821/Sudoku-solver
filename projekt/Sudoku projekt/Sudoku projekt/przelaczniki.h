#pragma once
#include <string>
#include <vector>
using namespace std;
/**Struktura ulatwiajaca przypisanie przelaczników do plikow*/
struct Parametry
{
	string in; //<wejscie
	string out; //<wyjscie
};

bool Para(Parametry& p, const vector<string>& params);

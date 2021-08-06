#pragma once
using namespace std;
const int N = 9;
bool wolne_pole(int tab[N][N], int& rzad, int& kol);
bool rozwiaz_sudoku(int tab[N][N]);
bool sprawdz_rzad(int tab[N][N], int rzad, int liczba);
bool sprawdz_kol(int tab[N][N], int kol, int liczba);
bool sprawdz_kostke(int tab[N][N], int liczba, int lewa, int prawa);
bool warunki(int tab[N][N], int rzad, int kol, int liczba);

  
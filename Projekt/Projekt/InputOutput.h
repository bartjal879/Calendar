/** file */
#pragma once
#include <iostream>
#include <fstream>
#include "klasy.h"

/** Funkcja szablonowa zapisuj¹ca utworzone wydarzenia, przechowywane w wektorze, do pliku
@param w Wektor przechwouj¹cy utworzone wydarzenia danego typu
@param plik Plik przechowuj¹cy utworzone w programie wydarzenia
@param i Indeks wydarzenia, które bêdzie zapisywane do pliku
*/
template <typename T>
void WypiszWydarzenieDopliku(const vector<T>& w, fstream &plik, int i)
{
	if (plik.good())
	{
		if (w.size() != 0)
		{
			plik << w[i].wydarzenie_nazwa << " ";
			plik << w[i].dzien << " " << w[i].miesiac << " " << w[i].rok << " ";
			plik << w[i].godzinaroz << " " << w[i].minutaroz << " " << w[i].wydarzenie_opis;
		}
	}
}

/** Funkcja wczytuj¹ca utworzone wydarzenia z pliku do wektora
@param w Wektor przechwouj¹cy utworzone wydarzenia danego typu
@param plik Plik przechowuj¹cy utworzone w programie wydarzenia
@param i Indeks wydarzenia, które jest wczytywane z pliku
*/
template<typename T>
void WczytajWydarzenieZPliku(vector<T> &u, fstream& plik, int i)
{
	if (plik.good())
	{
		if(u.size() != 0)
		plik >> u[i].wydarzenie_nazwa >> u[i].dzien >> u[i].miesiac >> u[i].rok >> u[i].godzinaroz >> u[i].minutaroz >> u[i].wydarzenie_opis;
	}
}

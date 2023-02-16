/*
Do zrobienia:
- usun wektor wydarzen
- dodaj input output

*/



#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "klasy.h"
#include "InputOutput.h"
using namespace std;

int main()
{
	cout << "Co chcesz zrobic? (Wybierz liczby 1-5 dla opcji ktora cie interesuje)\n1) Dodaj wydarzenie\n2) Wyswietl wydarzenia z danego roku\n3) Wyswietl wydarzenia z danego miesiaca\n4) Usun wydarzenie\n5) Wyjdz z programu\n";
	int p;
	Kalendarz kalendarz;
	kalendarz.WczytajZPliku();
	cin >> p;
	while (cin.fail())
	{
		cout << "Wprowadziles bledne dane" << endl;

		cin.clear();
		cin.ignore(1000, '\n');

		cout << "Wybierz liczby 1 - 5 dla opcji ktora cie interesuje\n1) Dodaj wydarzenie\n2) Wyswietl wydarzenia z danego roku\n3) Wyswietl wydarzenia z danego miesiaca\n4) Usun wydarzenie\n5) Wyjdz z programu\n";
		cin >> p;
	}
	while (p != 5)
	{
		if (p == 1)
		{
			kalendarz.DodajWydarzenie();
		}
		if (p == 2)
		{
			int r;
			cout << "Podaj rok, z ktorego chcesz wyswietlic wydarzeia: ";
			cin >> r;
			kalendarz.WyswietlWydarzeniePoRoku(r);
		}
		if (p == 3)
		{
			int m;
			cout << "1) Styczen 2) Luty 3) Marzec 4) Kwiecien 5) Maj 6) Czerwiec 7) Lipiec 8) Sierpien 9) Wrzesien 10) Pazdziernik 11) Listopad 12) Grudzien";
			cout << "Podaj miesiac (jako cyfre), z ktorego chcesz wyswietlic wydarzenia: ";
			cin >> m;
			kalendarz.WyswietlWydarzeniePoMiesiacu(m);
		}
		if (p == 4)
		{
			kalendarz.UsunWydarzenie();
		}
		cout << "-----------------------------------------------------------------" << endl;

		cout << "Co chcesz zrobic? (Wybierz liczby 1-5 dla opcji ktora cie interesuje)\n1) Dodaj wydarzenie\n2) Wyswietl wydarzenia z danego roku\n3) Wyswietl wydarzenia z danego miesiaca\n4) Usun wydarzenie\n5) Wyjdz z programu\n";
		cin >> p;
	} 
	kalendarz.ZapiszDoPliku();
	return 0;
}

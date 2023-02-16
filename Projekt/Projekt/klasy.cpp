#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include "klasy.h"
#include "OperacjeNaStringach.h"
#include "InputOutput.h"
using namespace std;

//data::data(int d, int m, int r)
//{
//	w.dzien = d;
//	miesiac = m;
//	rok = r;
//}
//
//data::~data()
//{
//}
//
//void data::wyswietld()
//{
//	cout << w.dzien << "." << miesiac << "." << rok;
//}
//
//godzina::godzina(int groz, int mroz, int gzak, int mzak)
//{
//	godzinaroz = groz;
//	minutaroz = mroz;
//	godzinazak = gzak;
//	minutazak = mzak;
//}
//
//godzina::~godzina()
//{
//}
//
//void godzina::wyswietlg() 
//{
//	cout << godzinaroz << ":" << minutaroz << " - " << godzinazak << ":" << minutazak;
//}

wydarzenie::wydarzenie(string n, int d , int m , int r, int gr, int mr,/* int gz, int mz,*/ string o)
{
	dzien = d;
	miesiac = m;
	rok = r;
	godzinaroz = gr;
	minutaroz = mr;
	wydarzenie_nazwa = n;
	wydarzenie_opis = o;
}

wydarzenie::~wydarzenie()
{
};

void wydarzenie::WyswietlWydarzenie()
{
	cout << wydarzenie_nazwa << " "; 

	cout << dzien << "." << miesiac << "." << rok;

	cout << " ";
		
	cout << godzinaroz << ":" << minutaroz;

	cout << "\nOpis wydarzenia: " << wydarzenie_opis << endl;
}

bool wydarzenie::operator < (const wydarzenie& rhs) const
{
	if (rok < rhs.rok)
		return true;
	else if (rok > rhs.rok)
		return false;
	else									// lata sa rowne
	{
		if (miesiac < rhs.miesiac)
			return true;
		else if (miesiac > rhs.miesiac)
			return false;
		else								// lata i miesiace sa rowne
		{
			if (dzien < rhs.dzien)
				return true;
			else if (dzien > rhs.dzien)
				return false;
			else							// lata miesiace i dni sa rowne
			{
				if (godzinaroz < rhs.godzinaroz)
					return true;
				else if (godzinaroz > rhs.godzinaroz)
					return false;
				else						// lata miesiace dni i godzinyrozp sa rowne
				{
					if (minutaroz < rhs.minutaroz)
						return true;
					else if (minutaroz > rhs.minutaroz)
						return true;
					else return false;		// wydarzenia rozpoczynajace sie od tej samej godziny tego samego dnia
				}

			}
		}
	}
}


Wzawodowe::Wzawodowe(string n, int d, int m, int r, int gr, int mr, /*int gz, int mz,*/ string o, string nr) :wydarzenie(n, d, m, r, gr, mr, o)
{
	numer_telefonu = nr;
}


void Wzawodowe::WyswietlWydarzenie()
{
	
	cout << " NAZWA WYDARZENIA: " << wydarzenie_nazwa << " ";
	cout << "\n DATA WYDARZENIA: " << dzien << ".";
	if (miesiac < 10)
		cout << "0" << miesiac << "." << rok;
	else cout << miesiac << "." << rok;
	cout << " ";
	if (godzinaroz < 10)
		cout << "0" << godzinaroz << ":";
	else cout << godzinaroz << ":";
	if (minutaroz < 10)
		cout << "0" << minutaroz;
	else cout << minutaroz;
	cout << "\n OPIS WYDARZENIA: " << wydarzenie_opis << endl;

	cout << " NUMER TELEFONU: " << numer_telefonu << endl << endl;
}
Wprywatne::Wprywatne(string n, int d, int m, int r, int gr, int mr, /*int gz, int mz,*/ string o, string msce) : wydarzenie(n, d, m, r, gr, mr,/*gz, mz,*/ o)
{
	miejsce = msce;
}
void Wprywatne::WyswietlWydarzenie()
{
	cout << " NAZWA WYDARZENIA: " << wydarzenie_nazwa << " ";
	cout << "\n DATA WYDARZENIA: " << dzien << ".";
	if (miesiac < 10)
		cout << "0" << miesiac << "." << rok;
	else cout << miesiac << "." << rok;
	cout << " ";
	if (godzinaroz < 10)
		cout << "0" << godzinaroz << ":";
	else cout << godzinaroz << ":";
	if (minutaroz < 10)
		cout << "0" << minutaroz;
	else cout << minutaroz;
	cout << "\n OPIS WYDARZENIA: " << wydarzenie_opis << endl;

	cout << " MIEJSCE: " << miejsce << endl << endl;
}
Wurzedowe::Wurzedowe(string n, int d, int m, int r, int gr, int mr, /*int gz, int mz,*/ string o, string u) : wydarzenie(n, d, m, r, gr, mr, /*gz, mz,*/ o)
{
	urzad = u;
}
void Wurzedowe::WyswietlWydarzenie()
{
	cout << " NAZWA WYDARZENIA: " << wydarzenie_nazwa << " ";
	cout << "\n DATA WYDARZENIA: " << dzien << ".";
	if (miesiac < 10)
		cout << "0" << miesiac << "." << rok;
	else cout << miesiac << "." << rok;
	cout << " ";
	if (godzinaroz < 10)
		cout << "0" << godzinaroz << ":";
	else cout << godzinaroz << ":";
	if (minutaroz < 10)
		cout << "0" << minutaroz;
	else cout << minutaroz;
	cout << "\n OPIS WYDARZENIA: " << wydarzenie_opis << endl;

	cout << " URZAD: " << urzad << endl << endl;
}

Kalendarz::Kalendarz(vector<Wzawodowe>& zaw, vector<Wprywatne>& pry, vector<Wurzedowe>& urz) :
	zawodowe(zaw), prywatne(pry), urzedowe(urz) {
	str = nullptr;
}

Kalendarz::Kalendarz()
{
	str = nullptr;
}

void Kalendarz::WyswietlWydarzeniePoRoku(int rok)
{
	int pomoc;
	int i = 0;
	pomoc = zawodowe.size() + prywatne.size() + urzedowe.size();
	for (int q = 0; q < zawodowe.size(); q++)
		if (zawodowe[q].rok == rok)
		{
			i++;
			cout << i << ") ";
			zawodowe[q].WyswietlWydarzenie();
		}
		else pomoc--;
	for (int q = 0; q < prywatne.size(); q++)
		if (prywatne[q].rok == rok)
		{
			i++;
			cout << i << ") ";
			prywatne[q].WyswietlWydarzenie();
		}
		else pomoc--;
	for (int q = 0; q < urzedowe.size(); q++)
		if (urzedowe[q].rok == rok)
		{
			i++;
			cout << i << ") ";
			urzedowe[q].WyswietlWydarzenie();
		}
		else pomoc--;
	if (pomoc == 0)
		cout << "W podanym roku nie posiadasz zadnego wydarzenia.\n";
}

void Kalendarz::WyswietlWydarzeniePoMiesiacu(int miesiac)
{
	int pomoc;
	int i = 0;
	pomoc = zawodowe.size() + prywatne.size() + urzedowe.size();
	for (int q = 0; q < zawodowe.size(); q++)
		if (zawodowe[q].miesiac == miesiac)
		{
			i++;
			cout << i << ") ";
			zawodowe[q].WyswietlWydarzenie();
		}
		else pomoc--;
	for (int q = 0; q < prywatne.size(); q++)
		if (prywatne[q].miesiac == miesiac)
		{
			i++;
			cout << i << ") ";
			prywatne[q].WyswietlWydarzenie();
		}
		else pomoc--;
	for (int q = 0; q < urzedowe.size(); q++)
		if (urzedowe[q].miesiac == miesiac)
		{
			i++;
			cout << i << ") ";
			urzedowe[q].WyswietlWydarzenie();
		}
		else pomoc--;
	if (pomoc == 0)
		cout << "W podanym miesiacu nie posiadasz zadnego wydarzenia.\n";
}


void Kalendarz::UsunWydarzenie()
{
	int r;
	cout << "Podaj kategorie wydarzenia, ktore chcesz usunac:" << endl;
	cout << "1) Zawodowe\n2) Prywatne\n3) Urzedowe\n";
	cin >> r;
	switch (r)
	{
	default:
		cout << "Nie mozna rozpoznac podanej kategorii. Wpisz liczbe 1 - 3";
	case 1:
		if (zawodowe.size() == 0)
		{
			cout << "W tej kategorii nie ma zadnych wydarzen" << endl << endl;
			break;
		}
		int x;
		cout << "Wybierz numer wydarzenia, ktore chcesz usunac" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < zawodowe.size(); i++)
		{
			cout << i + 1 << ") "; zawodowe[i].WyswietlWydarzenie();
		}
		cin >> x;
		if (x > zawodowe.size())
		{
			cout << "Takiego wydarzenia nie ma na liscie!";
			break;
		}
		zawodowe.erase(zawodowe.begin() + x);
		cout << "Wydarzenie zostalo usuniete pomyslnie" << endl;
		break;
	case 2:
		if (prywatne.size() == 0) 
		{
			cout << "W tej kategorii nie ma zadnych wydarzen" << endl << endl;
			break;
		}
		int y;
		cout << "Wybierz numer wydarzenia, ktore chcesz usunac" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < prywatne.size(); i++)
		{
			cout << i + 1 << ") "; prywatne[i].WyswietlWydarzenie();
		}
		cin >> y;
		if (y > prywatne.size() - 1)
		{
			cout << "Takiego wydarzenia nie ma na liscie!";
			break;
		}
		prywatne.erase(prywatne.begin() + y);
		cout << "Wydarzenie zostalo usuniete pomyslnie" << endl;
		break;
	case 3:
		if (urzedowe.size() == 0)
		{
			cout << "W tej kategorii nie ma zadnych wydarzen" << endl << endl;
			break;
		}
		int z;
		cout << "Wybierz numer wydarzenia, ktore chcesz usunac" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		for (int i = 0; i < urzedowe.size(); i++)
		{
			cout << i  + 1 << ") "; urzedowe[i].WyswietlWydarzenie();
		}
		cin >> z;
		if (z > urzedowe.size() - 1)
		{
			cout << "Takiego wydarzenia nie ma na liscie!";
			break;
		}
		urzedowe.erase(urzedowe.begin() + z);
		cout << "Wydarzenie zostalo usuniete pomyslnie" << endl;
		break;
	}
}
 void Kalendarz::WczytajZPliku()
{
	int i = 0;
	int j = 0;
	int k = 0;
	string pom;
	fstream plik;
	plik.open("kontener.txt", ios::in | ios::out);
	if (plik.good())
	{
		while (!plik.fail())
		{	
			plik >> pom;
			if (pom == "ZAWODOWE")
			{
				zawodowe.push_back(Wzawodowe());
				WczytajWydarzenieZPliku(zawodowe, plik, i);
				plik >> zawodowe[i].numer_telefonu;
				i++;
				pom = "";
				continue;
			}
			else if (pom == "PRYWATNE")
			{
				prywatne.push_back(Wprywatne());
				WczytajWydarzenieZPliku(prywatne, plik, j);
				plik >> prywatne[j].miejsce;
				j++;
				pom = "";
				continue;
			}
			else if (pom == "URZEDOWE")
			{
				urzedowe.push_back(Wurzedowe());
				WczytajWydarzenieZPliku(urzedowe, plik, k);
				plik >> urzedowe[k].urzad;
				k++;
				pom = "";
				continue;
			}
			else plik.close(); return;
		}
		plik.close();
	}

}
void Kalendarz::ZapiszDoPliku()//vector <Wzawodowe>& zaw, vector <Wprywatne>& pry, vector <Wurzedowe>& urz)
{
	fstream plik;
	plik.open("kontener.txt", std::ofstream::out | std::ofstream::trunc);
	plik.close();
	plik.open("kontener.txt", ios::in | ios::out);
	if (plik.good())
	{
		for (int i = 0; i < zawodowe.size(); i++)
		{
			plik << "ZAWODOWE ";
			WypiszWydarzenieDopliku(zawodowe, plik, i);
			plik << " " << zawodowe[i].numer_telefonu << endl;
		}
		for (int i = 0; i < prywatne.size(); i++)
		{
			plik << "PRYWATNE ";
			WypiszWydarzenieDopliku(prywatne, plik, i);
			plik << " " << prywatne[i].miejsce << endl;
		}
		for (int i = 0; i < urzedowe.size(); i++)
		{
			plik << "URZEDOWE ";
			WypiszWydarzenieDopliku(urzedowe, plik, i);
			plik << " " << urzedowe[i].urzad << endl;
		}
		plik.close();
	}
}

void Kalendarz::UstawAlgo(strategia* str)
{
	if (str == nullptr)
		this->str = str;
	else
	{
		UsunAlgo();
		this->str = str;
	}
}
	
void Kalendarz::UsunAlgo()
{
	if (str != nullptr)
	delete str;
};


Kalendarz::~Kalendarz()
{
	UsunAlgo();
}

void Kalendarz::DodajWydarzenie()
{
	try {
		enum miesiace { sty, lut, mar, kwi, maj, cze, lip, sie, wrz, paz, lis, gru };
		wydarzenie w;
		do
		{
			cout << "Podaj nazwe wydarzenia, ktore chcesz dodac: ";
			cin.ignore();
			getline(cin, w.wydarzenie_nazwa);
				
			cout << "Podaj dzien wydarzenia, ktore chcesz dodac: ";
			cin >> w.dzien;
			while (cin.fail())
			{
				cout << "Wprowadziles bledne dane" << endl;

				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Podaj dzien wydarzenia, ktore chcesz dodac: ";
				cin >> w.dzien;
			}
			while (w.dzien < 1 || w.dzien > 31)
			{
				cout << "Wprowadzono niepoprawny dzien. Wprowadz liczbe z zakresu 1 - 31\n";
				cout << "Podaj dzien wydarzenia, ktore chcesz dodac: ";
				cin >> w.dzien;
			}

			cout << "Podaj miesiac wydarzenia, ktore chcesz dodac: ";
			cin >> w.miesiac;
			while (cin.fail())
			{
				cout << "Wprowadziles bledne dane" << endl;

				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Podaj miesiac wydarzenia, ktore chcesz dodac: ";
				cin >> w.miesiac;
			}
			while (w.miesiac < 1 || w.miesiac > 12)
			{
				cout << "Wprowadzono niepoprawny miesiac. Wprowadz liczbe z zakresu 1 - 12\n";
				cout << "Podaj miesiac wydarzenia, ktore chcesz dodac: ";
				cin >> w.miesiac;
			}

			cout << "Podaj rok wydarzenia, ktore chcesz dodac: ";
			cin >> w.rok;
			while (cin.fail())
			{
				cout << "Wprowadziles bledne dane" << endl;

				cin.clear();
				cin.ignore(1000, '\n');

				cout << "Podaj rok wydarzenia, ktore chcesz dodac: ";
				cin >> w.rok;
			}

			if ((w.miesiac == lut + 1 && w.dzien > 28 && w.rok % 4 > 0) || (w.miesiac == lut + 1 && w.dzien > 29 && w.rok % 4 == 0) || (w.dzien > 30 && (w.miesiac == kwi + 1 || w.miesiac == cze + 1 || w.miesiac == wrz + 1 || w.miesiac == lis + 1)))
				cout << "\nJestes pewny, ze wprowadziles poprawna date ? \nSprawdz, czy wprowadzony przez ciebie dzien pojawia sie we wprowadzonym miesiacu.\n\n";
		} while ((w.miesiac == lut + 1 && w.dzien > 28 && w.rok % 4 > 0) || (w.miesiac == lut + 1 && w.dzien > 29 && w.rok % 4 == 0) || (w.dzien > 30 && (w.miesiac == kwi + 1 || w.miesiac == cze + 1 || w.miesiac == wrz + 1 || w.miesiac == lis + 1)));

		cout << "Podaj godzine rozpoczecia wydarzenia, ktore chcesz dodac: ";
		cin >> w.godzinaroz;
		while (cin.fail())
		{
			cout << "Wprowadziles bledne dane" << endl;

			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Podaj godzine rozpoczecia wydarzenia, ktore chcesz dodac: ";
			cin >> w.godzinaroz;
		}
		while (w.godzinaroz > 23 || w.godzinaroz < 0)
		{
			cout << "Wprowadzono niepoprawna godzine. Wprowadz liczbe z zakresu 0 - 23\n";
			cout << "Podaj godzine rozpoczecia wydarzenia, ktore chcesz dodac: ";
			cin >> w.godzinaroz;
		}

		cout << "Podaj minute rozpoczecia wydarzenia, ktore chcesz dodac: ";
		cin >> w.minutaroz;
		while (cin.fail())
		{
			cout << "Wprowadziles bledne dane" << endl;

			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Podaj minute rozpoczecie wydarzenia, ktore chcesz dodac: ";
			cin >> w.minutaroz;
		}
		while (w.minutaroz > 59 || w.minutaroz < 0)
		{
			cout << "Wprowadzono niepoprawna minute. Wprowadz liczbe z zakresu 0 - 59\n";
			cout << "Podaj minute rozpoczecia wydarzenia, ktore chcesz dodac: ";
			cin >> w.minutaroz;
		}

		//	cout << "Podaj godzine zakonczenia wydarzenia, ktore chcesz dodac: ";
		//	cin >> godzinazak;
		//	while (godzinazak > 23 || godzinazak < 0)
		//	{
		//		cout << "Wprowadzono niepoprawna godzine. Wprowadz liczbe z zakresu 0 - 23\n";
		//		cout << "Podaj godzine zakonczenia wydarzenia, ktore chcesz dodac: ";
		//		cin >> godzinazak;
		//	}
		//
		//	cout << "Podaj minute zakonczenia wydarzenia, ktore chcesz dodac: ";
		//	cin >> minutazak;
		//	while (minutazak > 59 || minutazak < 0)
		//	{
		//		cout << "Wprowadzono niepoprawna minute. Wprowadz liczbe z zakresu 0 - 59\n";
		//		cout << "Podaj minute zakonczenia wydarzenia, ktore chcesz dodac: ";
		//		cin >> minutazak;
		//	}
		cout << "Podaj opis wydarzenia, ktore chcesz dodac: ";
		cin.ignore();
		getline(cin, w.wydarzenie_opis);

		int numeralgo = 0;
		cout << "Podaj numer algorytmu, z ktorego chcesz korzystac:\n" << "1) Po opisie	2) Po nazwie\n";
		cin >> numeralgo;
		while (cin.fail())
		{
			cout << "Wprowadziles bledne dane" << endl;

			cin.clear();
			cin.ignore(1000, '\n');

			cout << "Podaj numer algorytmu, z ktorego chcesz korzystac: ";
			cin >> numeralgo;
		}
		switch(numeralgo)
		{			
		default:
			cout << "Niepoprawny numer algorytmu\n";
			return;
		case 1:
			str = new PoOpisie;
			break;
		case 2:
			str = new PoNazwie;
			break;
		}
		if (str->CzyZawodowe(w))
		{
			string nrtelefonu;
			cout << "Podaj numer telefonu, ktory chcesz powiazac z wydarzeniem: ";
			cin.ignore();
			getline(cin, nrtelefonu);
			UsunSpacje(nrtelefonu);
			
			while (nrtelefonu.size()!= 9 || CzyCyfry(nrtelefonu) == false)
			{
				cout << "Wprowadzono niepoprawny numer telefonu. Podaj 9 cyfrowy ciag cyfr." << endl;
				cout << "Podaj numer telefonu, ktory chcesz dodac: ";
				//cin.ignore();
				getline(cin, nrtelefonu);
			}
			zawodowe.push_back(Wzawodowe(w.wydarzenie_nazwa, w.dzien, w.miesiac, w.rok, w.godzinaroz, w.minutaroz,/* w.godzinazak, w.minutazak,*/ w.wydarzenie_opis, nrtelefonu));
			sort(zawodowe.begin(), zawodowe.end());
			return;
		}
		if (str->CzyPrywatne(w))
		{
			string miejsce;
			cout << "Wprowadz miejsce, ktore chcesz powiazac z wydarzeniem: ";
			cin.ignore();
			getline(cin, miejsce);
			prywatne.push_back(Wprywatne(w.wydarzenie_nazwa, w.dzien, w.miesiac, w.rok, w.godzinaroz, w.minutaroz,/* w.godzinazak, minutazak, */w.wydarzenie_opis, miejsce));
			sort(prywatne.begin(), prywatne.end());
			return;
		}
		if (str->CzyUrzedowe(w))
		{
			string urzad;
			cout << "Wprowadz urzad, ktory chcesz powiazac z wydarzeniem: ";
			cin.ignore();
			getline(cin, urzad);
			urzedowe.push_back(Wurzedowe(w.wydarzenie_nazwa, w.dzien, w.miesiac, w.rok, w.godzinaroz, w.minutaroz,/* godzinazak, minutazak, */w.wydarzenie_opis, urzad));
			sort(urzedowe.begin(), urzedowe.end());
			return;
		}
	
	
	
	throw - 1;
	}
	catch (int e)
	{
		if (e == -1)
		{
			cout << "Blad: Wydarzenie nie moglo zostac zakwalifikowane do zadnej kategorii (Zawodowe, Prywatne, Urzedowe)" << endl;
			throw;
		}
		else
		{
			cout << "Nierozpoznany b³¹d";
			throw;
		}
	}
}

bool PoOpisie::CzyZawodowe(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_opis);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "praca");
	wynik = wynik + CzyZawiera(temp, "pracy");
	wynik = wynik + CzyZawiera(temp, "prace");
	wynik = wynik + CzyZawiera(temp, "pracka");
	wynik = wynik + CzyZawiera(temp, "pracke");
	wynik = wynik + CzyZawiera(temp, "robota");
	wynik = wynik + CzyZawiera(temp, "roboty");
	wynik = wynik + CzyZawiera(temp, "robote");
	wynik = wynik + CzyZawiera(temp, "biuro");
	wynik = wynik + CzyZawiera(temp, "biura");
	return wynik;
}

bool PoOpisie::CzyPrywatne(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_opis);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "wakacje");
	wynik = wynik + CzyZawiera(temp, "gril");
	wynik = wynik + CzyZawiera(temp, "spotkanie");
	wynik = wynik + CzyZawiera(temp, "rodzina");
	wynik = wynik + CzyZawiera(temp, "mama");
	wynik = wynik + CzyZawiera(temp, "mamy");
	wynik = wynik + CzyZawiera(temp, "tata");
	wynik = wynik + CzyZawiera(temp, "taty");
	wynik = wynik + CzyZawiera(temp, "corka");
	wynik = wynik + CzyZawiera(temp, "corki");
	wynik = wynik + CzyZawiera(temp, "syn");
	wynik = wynik + CzyZawiera(temp, "synka");
	wynik = wynik + CzyZawiera(temp, "wyjazd");
	return wynik;
}

bool PoOpisie::CzyUrzedowe(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_opis);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "urzad");
	wynik = wynik + CzyZawiera(temp, "urzedowe");
	wynik = wynik + CzyZawiera(temp, "urzedu");
	wynik = wynik + CzyZawiera(temp, "urzedem");
	wynik = wynik + CzyZawiera(temp, "podatki");
	wynik = wynik + CzyZawiera(temp, "podatek");
	wynik = wynik + CzyZawiera(temp, "podatkowe");
	wynik = wynik + CzyZawiera(temp, "podatkowy");
	wynik = wynik + CzyZawiera(temp, "rachunki");
	wynik = wynik + CzyZawiera(temp, "rozliczenie");
	wynik = wynik + CzyZawiera(temp, "rachunkowy");
	wynik = wynik + CzyZawiera(temp, "pit");
	return wynik;
}

bool PoNazwie::CzyZawodowe(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_nazwa);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "praca");
	wynik = wynik + CzyZawiera(temp, "pracy");
	wynik = wynik + CzyZawiera(temp, "prace");
	wynik = wynik + CzyZawiera(temp, "pracka");
	wynik = wynik + CzyZawiera(temp, "pracke");
	wynik = wynik + CzyZawiera(temp, "robota");
	wynik = wynik + CzyZawiera(temp, "roboty");
	wynik = wynik + CzyZawiera(temp, "robote");
	wynik = wynik + CzyZawiera(temp, "biuro");
	wynik = wynik + CzyZawiera(temp, "biura");
	return wynik;
}

bool PoNazwie::CzyPrywatne(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_nazwa);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "wakacje");
	wynik = wynik + CzyZawiera(temp, "gril");
	wynik = wynik + CzyZawiera(temp, "spotkanie");
	wynik = wynik + CzyZawiera(temp, "rodzina");
	wynik = wynik + CzyZawiera(temp, "mama");
	wynik = wynik + CzyZawiera(temp, "mamy");
	wynik = wynik + CzyZawiera(temp, "tata");
	wynik = wynik + CzyZawiera(temp, "taty");
	wynik = wynik + CzyZawiera(temp, "corka");
	wynik = wynik + CzyZawiera(temp, "corki");
	wynik = wynik + CzyZawiera(temp, "syn");
	wynik = wynik + CzyZawiera(temp, "synka");
	wynik = wynik + CzyZawiera(temp, "wyjazd");
	return wynik;
}

bool PoNazwie::CzyUrzedowe(const wydarzenie& w)
{
	string temp = NaMaleLitery(w.wydarzenie_nazwa);
	UsunSpacje(temp);
	bool wynik = CzyZawiera(temp, "urzad");
	wynik = wynik + CzyZawiera(temp, "urzedowe");
	wynik = wynik + CzyZawiera(temp, "urzedu");
	wynik = wynik + CzyZawiera(temp, "urzedem");
	wynik = wynik + CzyZawiera(temp, "podatki");
	wynik = wynik + CzyZawiera(temp, "podatek");
	wynik = wynik + CzyZawiera(temp, "podatkowe");
	wynik = wynik + CzyZawiera(temp, "podatkowy");
	wynik = wynik + CzyZawiera(temp, "rachunki");
	wynik = wynik + CzyZawiera(temp, "rozliczenie");
	wynik = wynik + CzyZawiera(temp, "rachunkowy");
	wynik = wynik + CzyZawiera(temp, "pit");
	return wynik;
}

/** file */
#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Klasa abstrakcyjna reprezentująca wydarzenie*/
class wydarzenie
{
public:
	int dzien,						///< dzień wydarzenia
		miesiac,					///< miesiąc wydarzenia
		rok, 						///< rok wydarzenia
		godzinaroz, 				///< godzina rozpoczęcia wydarzenia
		minutaroz;					///< minuta rozpoczęcia wydarzenia
	string wydarzenie_nazwa;		///< nazwa wydarzenia
	string wydarzenie_opis;			///< opis wydarzenia 

	/** Konstruktor inicjalizujący wartościami atrybuty utworzonego obiektu klasy wydarzenie*/
	wydarzenie(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0,*/ string = "brak");	//(nazwa, dzien, miesiac, rok, godzinab rozp., minuta rozp., godzina zak., minuta zak.)
	~wydarzenie();
	/** Metoda wirtualna wyswietlająca wydarzenie*/
	virtual void WyswietlWydarzenie();
	/** Metoda przeciążająca operator mniejszości*/
	bool operator < (const wydarzenie& rhs) const;
//	{
//		if (rok < rhs.rok)
//			return true;
//		else if (rok > rhs.rok)
//			return false;
//		else									// lata sa rowne
//		{
//			if (miesiac < rhs.miesiac)
//				return true;
//			else if (miesiac > rhs.miesiac)
//				return false;
//			else								// lata i miesiace sa rowne
//			{
//				if (dzien < rhs.dzien)
//					return true;
//				else if (dzien > rhs.dzien)
//					return false;
//				else							// lata miesiace i dni sa rowne
//				{
//					if (godzinaroz < rhs.godzinaroz)
//						return true;
//					else if (godzinaroz > rhs.godzinaroz)
//						return false;
//					else						// lata miesiace dni i godzinyrozp sa rowne
//					{
//						if (minutaroz < rhs.minutaroz)
//							return true;
//						else if (minutaroz > rhs.minutaroz)
//							return true;
//						else return false;		// wydarzenia rozpoczynajace sie od tej samej godziny tego samego dnia
//					}
//
//				}
//			}
//		}
//	}
//
};

/** Klasa reprezentująca wydarzenie zawodowe*/
class Wzawodowe : public wydarzenie
{
public:
	string numer_telefonu;
	Wzawodowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /*int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();

};

/** Klasa reprezentująca wydarzenie prywatne*/
class Wprywatne : public wydarzenie
{
public:
	string miejsce;
	Wprywatne(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();
};

/** Klasa reprezentująca wydarzenie urzędowe*/
class Wurzedowe : public wydarzenie
{
public:
	string urzad;
	Wurzedowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /* int = 0, int = 0,*/ string = "brak", string = "brak");
	void WyswietlWydarzenie();
};
class strategia;

/** Klasa reprezentująca kalendarz, w którym znajdują się wszystkie utworzone przez użytkownika wydarzenia*/
class Kalendarz
{
	strategia * str;								///< wskaźnik na obiekt/klasę typu strategia
public:
	vector <Wzawodowe> zawodowe;					///< wektor przechowujący wydarzenia zawodowe
	vector <Wprywatne> prywatne;					///< wektor przechowujący wydarzenia prywatne
	vector <Wurzedowe> urzedowe;					///< wektor przechowujący wydarzenia urzędowe

	/** Konstruktor inicjalizujący atrybuty utworzonego obiektu klasy Kalendarz*/
	Kalendarz(vector <Wzawodowe>& zaw, vector <Wprywatne>& pry, vector <Wurzedowe>& urz);
	/** Konstruktor bezargumentowy inicjalizujący atrybut strategia * str na nullptr*/
	Kalendarz();
	/** Destruktor wywołujący metodę UsunAlgo, która usuwa zaalokowaną pamięć*/
	~Kalendarz();
	/** Metoda wczytująca od użytkownika wartości atrybutów klasy wydarzenie i klas po niej dziedziczących*/
	void DodajWydarzenie();
	/** Metoda wyświetlająca wszystkie wydarzenia z podanego roku
	@param rok Rok, z którego metoda ma wyświetlić wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoRoku(int rok);
	/** Metoda wyświetlająca wszystkie wydarzenia z podanego miesiąca
	@param miesiac Miesiąc, z którego funkcja ma wyświetlić wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoMiesiacu(int miesiac);
	//void AktualizujWydarzenie();
	/** Metoda usuwająca z odpowiedniego wektora wydarzenie, które użytkownik podał*/
	void UsunWydarzenie();
	/** Metoda wczytująca zapisane w pliku kontener.txt, wcześniej utworzone przez użytkownika wydarzenia*/
	void WczytajZPliku();
	/** Metoda zapisująca dodane przez użytkownika wydarzenia w pliku tekstowym kontener.txt*/
	void ZapiszDoPliku();
	/** Metoda ustawiająca na odpowiednią algorytm wskaźnik klasy wydarzenie*/
	void UstawAlgo(strategia* str);
	/** Metoda usuwająca zaalokowaną podczas tworzenia wskaźnika pamięc*/
	void UsunAlgo();
};

/** Klasa czysto abstrakcyjna pozwalająca na wybranie możliwego algorytmu*/
class strategia
{
public:
	/** Metoda wirtualna */
	virtual bool CzyZawodowe(const wydarzenie& temp) = 0;	
	/** Metoda wirtualna */
	virtual bool CzyPrywatne(const wydarzenie& temp) = 0;
	/** Metoda wirtualna */
	virtual bool CzyUrzedowe(const wydarzenie& temp) = 0;
};
/** Klasa dziedzicząca po klasie strategia reprezentująca algorytm wyszukiwania po nazwie*/
class PoNazwie :public strategia
{
public:
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń urzędowych */
	bool CzyUrzedowe(const wydarzenie& temp) override;
};

/** Klasa dziedzicząca po klasie strategia reprezentująca algorytm wyszukiwania po opisie*/
class PoOpisie : public strategia
{
public:
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzająca, czy wydarzenie może zostać zakwalifikowane do wydarzeń urzędowych */
	bool CzyUrzedowe(const wydarzenie& temp) override;
};

//template <typename T>
//class DzialaniaNaPlikach
//{
//public:
//	ZapiszDoPliku(const vector &<T> wek, int i)
//	{
//		fstream plik;
//		if (plik.good())
//		{
//			if (wek.size() != 0)
//			{
//				plik << T[i].wydarzenie_nazwa << ", ";
//				plik << T[i].dzien << ", " << T[i].miesiac << ", " << T[i].rok << ", ";
//				plik << T[i].godzinaroz << ", " << T[i].minutaroz << ", " << T[i].wydarzenie_opis << ", ";
//			}
//		}
//	}
//
//};

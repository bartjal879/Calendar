/** file */
#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Klasa abstrakcyjna reprezentuj�ca wydarzenie*/
class wydarzenie
{
public:
	int dzien,						///< dzie� wydarzenia
		miesiac,					///< miesi�c wydarzenia
		rok, 						///< rok wydarzenia
		godzinaroz, 				///< godzina rozpocz�cia wydarzenia
		minutaroz;					///< minuta rozpocz�cia wydarzenia
	string wydarzenie_nazwa;		///< nazwa wydarzenia
	string wydarzenie_opis;			///< opis wydarzenia 

	/** Konstruktor inicjalizuj�cy warto�ciami atrybuty utworzonego obiektu klasy wydarzenie*/
	wydarzenie(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0,*/ string = "brak");	//(nazwa, dzien, miesiac, rok, godzinab rozp., minuta rozp., godzina zak., minuta zak.)
	~wydarzenie();
	/** Metoda wirtualna wyswietlaj�ca wydarzenie*/
	virtual void WyswietlWydarzenie();
	/** Metoda przeci��aj�ca operator mniejszo�ci*/
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

/** Klasa reprezentuj�ca wydarzenie zawodowe*/
class Wzawodowe : public wydarzenie
{
public:
	string numer_telefonu;
	Wzawodowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /*int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();

};

/** Klasa reprezentuj�ca wydarzenie prywatne*/
class Wprywatne : public wydarzenie
{
public:
	string miejsce;
	Wprywatne(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();
};

/** Klasa reprezentuj�ca wydarzenie urz�dowe*/
class Wurzedowe : public wydarzenie
{
public:
	string urzad;
	Wurzedowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /* int = 0, int = 0,*/ string = "brak", string = "brak");
	void WyswietlWydarzenie();
};
class strategia;

/** Klasa reprezentuj�ca kalendarz, w kt�rym znajduj� si� wszystkie utworzone przez u�ytkownika wydarzenia*/
class Kalendarz
{
	strategia * str;								///< wska�nik na obiekt/klas� typu strategia
public:
	vector <Wzawodowe> zawodowe;					///< wektor przechowuj�cy wydarzenia zawodowe
	vector <Wprywatne> prywatne;					///< wektor przechowuj�cy wydarzenia prywatne
	vector <Wurzedowe> urzedowe;					///< wektor przechowuj�cy wydarzenia urz�dowe

	/** Konstruktor inicjalizuj�cy atrybuty utworzonego obiektu klasy Kalendarz*/
	Kalendarz(vector <Wzawodowe>& zaw, vector <Wprywatne>& pry, vector <Wurzedowe>& urz);
	/** Konstruktor bezargumentowy inicjalizuj�cy atrybut strategia * str na nullptr*/
	Kalendarz();
	/** Destruktor wywo�uj�cy metod� UsunAlgo, kt�ra usuwa zaalokowan� pami��*/
	~Kalendarz();
	/** Metoda wczytuj�ca od u�ytkownika warto�ci atrybut�w klasy wydarzenie i klas po niej dziedzicz�cych*/
	void DodajWydarzenie();
	/** Metoda wy�wietlaj�ca wszystkie wydarzenia z podanego roku
	@param rok Rok, z kt�rego metoda ma wy�wietli� wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoRoku(int rok);
	/** Metoda wy�wietlaj�ca wszystkie wydarzenia z podanego miesi�ca
	@param miesiac Miesi�c, z kt�rego funkcja ma wy�wietli� wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoMiesiacu(int miesiac);
	//void AktualizujWydarzenie();
	/** Metoda usuwaj�ca z odpowiedniego wektora wydarzenie, kt�re u�ytkownik poda�*/
	void UsunWydarzenie();
	/** Metoda wczytuj�ca zapisane w pliku kontener.txt, wcze�niej utworzone przez u�ytkownika wydarzenia*/
	void WczytajZPliku();
	/** Metoda zapisuj�ca dodane przez u�ytkownika wydarzenia w pliku tekstowym kontener.txt*/
	void ZapiszDoPliku();
	/** Metoda ustawiaj�ca na odpowiedni� algorytm wska�nik klasy wydarzenie*/
	void UstawAlgo(strategia* str);
	/** Metoda usuwaj�ca zaalokowan� podczas tworzenia wska�nika pami�c*/
	void UsunAlgo();
};

/** Klasa czysto abstrakcyjna pozwalaj�ca na wybranie mo�liwego algorytmu*/
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
/** Klasa dziedzicz�ca po klasie strategia reprezentuj�ca algorytm wyszukiwania po nazwie*/
class PoNazwie :public strategia
{
public:
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� urz�dowych */
	bool CzyUrzedowe(const wydarzenie& temp) override;
};

/** Klasa dziedzicz�ca po klasie strategia reprezentuj�ca algorytm wyszukiwania po opisie*/
class PoOpisie : public strategia
{
public:
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzaj�ca, czy wydarzenie mo�e zosta� zakwalifikowane do wydarze� urz�dowych */
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

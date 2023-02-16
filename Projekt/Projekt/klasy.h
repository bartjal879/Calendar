/** file */
#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** Klasa abstrakcyjna reprezentuj¹ca wydarzenie*/
class wydarzenie
{
public:
	int dzien,						///< dzieñ wydarzenia
		miesiac,					///< miesi¹c wydarzenia
		rok, 						///< rok wydarzenia
		godzinaroz, 				///< godzina rozpoczêcia wydarzenia
		minutaroz;					///< minuta rozpoczêcia wydarzenia
	string wydarzenie_nazwa;		///< nazwa wydarzenia
	string wydarzenie_opis;			///< opis wydarzenia 

	/** Konstruktor inicjalizuj¹cy wartoœciami atrybuty utworzonego obiektu klasy wydarzenie*/
	wydarzenie(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0,*/ string = "brak");	//(nazwa, dzien, miesiac, rok, godzinab rozp., minuta rozp., godzina zak., minuta zak.)
	~wydarzenie();
	/** Metoda wirtualna wyswietlaj¹ca wydarzenie*/
	virtual void WyswietlWydarzenie();
	/** Metoda przeci¹¿aj¹ca operator mniejszoœci*/
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

/** Klasa reprezentuj¹ca wydarzenie zawodowe*/
class Wzawodowe : public wydarzenie
{
public:
	string numer_telefonu;
	Wzawodowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /*int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();

};

/** Klasa reprezentuj¹ca wydarzenie prywatne*/
class Wprywatne : public wydarzenie
{
public:
	string miejsce;
	Wprywatne(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0,/* int = 0, int = 0, */string = "brak", string = "brak");
	void WyswietlWydarzenie();
};

/** Klasa reprezentuj¹ca wydarzenie urzêdowe*/
class Wurzedowe : public wydarzenie
{
public:
	string urzad;
	Wurzedowe(string = "brak", int = 0, int = 0, int = 0, int = 0, int = 0, /* int = 0, int = 0,*/ string = "brak", string = "brak");
	void WyswietlWydarzenie();
};
class strategia;

/** Klasa reprezentuj¹ca kalendarz, w którym znajduj¹ siê wszystkie utworzone przez u¿ytkownika wydarzenia*/
class Kalendarz
{
	strategia * str;								///< wskaŸnik na obiekt/klasê typu strategia
public:
	vector <Wzawodowe> zawodowe;					///< wektor przechowuj¹cy wydarzenia zawodowe
	vector <Wprywatne> prywatne;					///< wektor przechowuj¹cy wydarzenia prywatne
	vector <Wurzedowe> urzedowe;					///< wektor przechowuj¹cy wydarzenia urzêdowe

	/** Konstruktor inicjalizuj¹cy atrybuty utworzonego obiektu klasy Kalendarz*/
	Kalendarz(vector <Wzawodowe>& zaw, vector <Wprywatne>& pry, vector <Wurzedowe>& urz);
	/** Konstruktor bezargumentowy inicjalizuj¹cy atrybut strategia * str na nullptr*/
	Kalendarz();
	/** Destruktor wywo³uj¹cy metodê UsunAlgo, która usuwa zaalokowan¹ pamiêæ*/
	~Kalendarz();
	/** Metoda wczytuj¹ca od u¿ytkownika wartoœci atrybutów klasy wydarzenie i klas po niej dziedzicz¹cych*/
	void DodajWydarzenie();
	/** Metoda wyœwietlaj¹ca wszystkie wydarzenia z podanego roku
	@param rok Rok, z którego metoda ma wyœwietliæ wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoRoku(int rok);
	/** Metoda wyœwietlaj¹ca wszystkie wydarzenia z podanego miesi¹ca
	@param miesiac Miesi¹c, z którego funkcja ma wyœwietliæ wszystkie wydarzenia
	*/
	void WyswietlWydarzeniePoMiesiacu(int miesiac);
	//void AktualizujWydarzenie();
	/** Metoda usuwaj¹ca z odpowiedniego wektora wydarzenie, które u¿ytkownik poda³*/
	void UsunWydarzenie();
	/** Metoda wczytuj¹ca zapisane w pliku kontener.txt, wczeœniej utworzone przez u¿ytkownika wydarzenia*/
	void WczytajZPliku();
	/** Metoda zapisuj¹ca dodane przez u¿ytkownika wydarzenia w pliku tekstowym kontener.txt*/
	void ZapiszDoPliku();
	/** Metoda ustawiaj¹ca na odpowiedni¹ algorytm wskaŸnik klasy wydarzenie*/
	void UstawAlgo(strategia* str);
	/** Metoda usuwaj¹ca zaalokowan¹ podczas tworzenia wskaŸnika pamiêc*/
	void UsunAlgo();
};

/** Klasa czysto abstrakcyjna pozwalaj¹ca na wybranie mo¿liwego algorytmu*/
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
/** Klasa dziedzicz¹ca po klasie strategia reprezentuj¹ca algorytm wyszukiwania po nazwie*/
class PoNazwie :public strategia
{
public:
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ urzêdowych */
	bool CzyUrzedowe(const wydarzenie& temp) override;
};

/** Klasa dziedzicz¹ca po klasie strategia reprezentuj¹ca algorytm wyszukiwania po opisie*/
class PoOpisie : public strategia
{
public:
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ zawodowych */
	bool CzyZawodowe(const wydarzenie& temp) override;
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ prywatnych */
	bool CzyPrywatne(const wydarzenie& temp) override;
	/** Metoda sprawdzaj¹ca, czy wydarzenie mo¿e zostaæ zakwalifikowane do wydarzeñ urzêdowych */
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

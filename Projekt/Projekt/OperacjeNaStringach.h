/** file */

#pragma once
#include <iostream>
#include <string>
using namespace std;

/** Funkcja zamieniaj�ca wszystkie litery w danym ci�gu znak�w na ma�e
@param dana Ci�g znak�w reprezentuj�cy opis wydarzenia
@return Ci�g znak�w reprezentruj�cy opis wydarzenia sk�adaj�cy si� z samych ma�ych liter  
*/
string NaMaleLitery(string dana);

/** Funkcja usuwaj�ca z tesktu wszystkie bia�e znaki
@param[out] temp Ci�g znak�w, z kt�ego funkcja usuwa bia�e znaki 
*/
void UsunSpacje(string& temp);

/** Funkcja sprawdza, czy podany ciag znakow sklada sie tylko z cyfr
@param[out] Ci�g znak�w, kt�ry funkcja sparwdza
@return Czy ci�zg znak�w sk�ada si� tylko z cyfr
*/
bool CzyCyfry(const string& str);

/** Funkcja sprawdzaj�ca czy w podanym tek�cie (Ci�gu znak�w) znajduje si� okre�lone s�owo
* @param[out] temp Ci�g znak�w, kt�ry funkcja sprawdza
* @param slowo S�owo, kt�re wyszukiwane jest w ci�gu znak�w
* @return
*/
bool CzyZawiera(const string &temp, string slowo);


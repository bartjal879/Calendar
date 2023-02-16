/** file */

#pragma once
#include <iostream>
#include <string>
using namespace std;

/** Funkcja zamieniaj¹ca wszystkie litery w danym ci¹gu znaków na ma³e
@param dana Ci¹g znaków reprezentuj¹cy opis wydarzenia
@return Ci¹g znaków reprezentruj¹cy opis wydarzenia sk³adaj¹cy siê z samych ma³ych liter  
*/
string NaMaleLitery(string dana);

/** Funkcja usuwaj¹ca z tesktu wszystkie bia³e znaki
@param[out] temp Ci¹g znaków, z któego funkcja usuwa bia³e znaki 
*/
void UsunSpacje(string& temp);

/** Funkcja sprawdza, czy podany ciag znakow sklada sie tylko z cyfr
@param[out] Ci¹g znaków, który funkcja sparwdza
@return Czy ci¹zg znaków sk³ada siê tylko z cyfr
*/
bool CzyCyfry(const string& str);

/** Funkcja sprawdzaj¹ca czy w podanym tekœcie (Ci¹gu znaków) znajduje siê okreœlone s³owo
* @param[out] temp Ci¹g znaków, który funkcja sprawdza
* @param slowo S³owo, które wyszukiwane jest w ci¹gu znaków
* @return
*/
bool CzyZawiera(const string &temp, string slowo);


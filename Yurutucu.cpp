

// Yurutucu dosyas�

#include <iostream>
#include "TahminOyunu.h" // yazd���m�zyeni k�t�phanemiz
using namespace std;
int main()
{
	TahminOyunu nsn = TahminOyunu(); // nsn ad�nda bir bir nesne olu�turulur
	nsn.OyunOyna(); // OyunOyna() fonksiyonu public oldu�u i�in nsn nesnesi ona eri�ebilir. Oyun ba�lat�l�r.
	return 0;
}
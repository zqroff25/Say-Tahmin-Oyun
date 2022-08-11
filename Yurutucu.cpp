

// Yurutucu dosyasý

#include <iostream>
#include "TahminOyunu.h" // yazdýðýmýzyeni kütüphanemiz
using namespace std;
int main()
{
	TahminOyunu nsn = TahminOyunu(); // nsn adýnda bir bir nesne oluþturulur
	nsn.OyunOyna(); // OyunOyna() fonksiyonu public olduðu için nsn nesnesi ona eriþebilir. Oyun baþlatýlýr.
	return 0;
}
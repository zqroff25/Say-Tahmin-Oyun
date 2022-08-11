#include "TahminOyunu.h"

#include <iostream> // cin ve cout fonksiyonlar�n� kullanmak i�in
#include <cstdlib> // rasgele say�lar olu�turmak i�in
#include <string> // do�ru tahmin edilen say�n�n x lerden olu�an diziye aktar�lmas� to_string() fonksiyonu ile yap�lm��t�r (141. sat�rda)
#include <ctime> // epoch time

using namespace std;

TahminOyunu::TahminOyunu()
{
	cout << "Dizideki Rakam Sayisini Giriniz :"; cin >> kullanici_Eleman_Girisi; // kullan�c�dan ka� eleman ile oynamak istedi�i al�n�r
	if (kullanici_Eleman_Girisi < 2 || kullanici_Eleman_Girisi>20) // al�nan de�erin 2 ile 20 aras�nda olmas� beklenmektedir
	{
		cout << "En az 2 En cok 20 Eleman Girebilirsiniz !" << endl;
		elemanKontrol = true; // al�nan de�er ilgili aral�kta de�ilse elemanKontrol de�ikeni aktif edilir ve program biter ( 43. sat�rda)
	}
	else
	{
		rasgele_AltLimit = 1; // alt limit 1 olarak verilmiş
		rasgele_UstLimit = 6; // üst limit 6 olarak verilmiş
		oyun_Tahmin_Sayisi = kullanici_Eleman_Girisi * 2; // tahmin say�s� eleman say�s�n�n 2 kat� olarak verilmi�
	}
}

//En �nemli fonksiyondur! B�t�n i�lemler burada yap�lmaktad�r. ( public)
void TahminOyunu::OyunOyna() // parametre almayan tek public �ye fonksiyon
{
	if (elemanKontrol == false) // e�er girilen eleman say�s� 2 ile 20 aral���nda ise 
	{
		bool sonDurum = false; // oyunun son durumunu kontrol etmek i�in kullan�r�z. Kazand�n�z ya da kaybettiniz !
		cout << endl;
		cout << "OYUN BASLADI" << endl;
		Diziyi_Olustur(depoDizi, kullanici_Eleman_Girisi, rasgele_AltLimit, rasgele_UstLimit); // ilgili parametrelere g�re diziyi olu�tur
		for (int i = 0; i < oyun_Tahmin_Sayisi; i++) // tahmin say�s� kadar oyun oynanmal�
		{
			cout << endl;
			tahminKontrol = false; // tahmin edilen say�n�n daha �nceden  kullan�ld���n� anlamak i�in kullan�r�z
			cout << "Bir rakam tahmin edin :"; cin >> tahmin; // tahminin kullan�c�dan al�nmas�
			tahminDizi[i] = tahmin; // tahmin edilen say�lar�n ba�ka bir dizide depolanmas� gerekir
			for (int j = 0; j < i; j++)
			{
				if (tahminDizi[j] == tahmin) // e�er tahmin edilen say� daha �nceden kullan�lm��sa
				{
					tahminKontrol = true; // aktif edilir
					tahminDizi[i] = 0;
					oyun_Tahmin_Sayisi--; // kullan�c�n�n tahmin haklar�ndan 1 azalt�l�r
					break; // d�ng�den ��k�l�r
				}
			}
			if (tahminKontrol == true) // aktif ise
			{
				cout << "Ayni rakami tekrar giremezsiniz !" << endl << endl; // uyar� ver ve bir sonraki iterasyondan devam et
				continue;
			}
			else
			{
				tahminVarMi = Sayi_Dizide_Var_Mi(depoDizi, xlerden_OLusan_Dizi, tahmin, kullanici_Eleman_Girisi); // tahmin edilen say�n�n rasgele say�lardan olu�an depoDizisinde olup olmad��� kontrol edilir
				if (tahminVarMi == false) // e�er tahmin edilen say� depoDizisinde yoksa i�eri�i g�ster ve uyar� ver
				{
					cout << endl;
					cout << "dizi icerigi :" << endl;
					Sonuclari_Goster(); // tahmin edilen ve edilemeyen say�lar�n durumunu g�steriri
					cout << endl;
					cout << "Rakam Bulunamadi !" << endl;
					continue; // bir sonraki iterasyondan devam et
				}
				// tahmin edilen say� depoDizi sinde varsa
				cout << endl;
				cout << "dizi icerigi :" << endl;
				Sonuclari_Goster(); // i�eri�i g�ster
				cout << endl;
			}
			sonDurum = Kazan_Kaybet(depoDizi, tahminDizi, kazanKaybet, kazandiMi); // �retilen rasgele say�lardan ka� tanesi bilinmi�
			if (sonDurum == true) // e�er rasgele �retilen b�t�n say�lar bilinmi�se oyunu kazand�n�z
			{
				cout << endl;
				cout << "Tebrikler KAZANDINIZ :)" << endl;
				break; // b�t�n oyunu bitir
			}
		}
		if (sonDurum == false) // e�er rasgele �retilen b�t�n say�lar bilinememi�se, oyunu kaybettiniz
		{
			cout << endl;
			cout << "Uzgunuz KAYBETTINIZ :(" << endl;
			cout << endl;
		}
	}
}


// diziyi olu�turma fonksiyonu ( private )
void TahminOyunu::Diziyi_Olustur(int depoDizi[], int kullanici_Eleman_Girisi, int rasgele_AltLimit, int rasgele_UstLimit)
{
	int rasgele_Sayi = 0;
	srand(static_cast<int>(time(0))); // rasgele say�lar �retebilmek i�in �ekirde�i 0 yapmak gerkir
	cout << "Rasgele Sayilar Olusturuldu !" << endl;
	for (int i = 0; i < kullanici_Eleman_Girisi; i++) // girilen eleman say�s� kadar rasgele say� �retilir ve diziye aktar�l�r
	{
		rasgele_Sayi = rand() % rasgele_UstLimit + rasgele_AltLimit; // rasgele say� olu�turulur
		depoDizi[i] = rasgele_Sayi;
		//cout << depoDizi[i] << " ";  // Bu kod par�as�n� aktif ederek hangi rasgele say�lar�n �retildi�ini g�rebilirsiniz.
	}
	cout << endl;
	Xlerden_OLusan_Diziyi_Olsutur(xlerden_OLusan_Dizi, kullanici_Eleman_Girisi); // alt fonksiyon kullan�m� g�sterilmi�tir
	cout << endl; // oyun ba�lad���nda dizi i�eri�i olarak  X X X X X... g�sterilmektedir

}

// �reitlen rasgele say�lar�n oldu�u diziyi gizlemek i�in kullan�lan x lerden olu�an diziyi olu�turur ( private )
void TahminOyunu::Xlerden_OLusan_Diziyi_Olsutur(string xlerden_OLusan_Dizi[], int kullanici_Eleman_Girisi)
{
	for (int i = 0; i < kullanici_Eleman_Girisi; i++) // girilen eleman say�s� kadar X eklenir
	{
		xlerden_OLusan_Dizi[i] = "X";
		cout << xlerden_OLusan_Dizi[i] << " ";
	}
}


// tahmin edilen say�n�n, rasgele �retilen say�larla dolu olan depoDizi sinde olup olmad��� kontrol edilir
// e�er varsa geriye true, yoksa false sonucu d�ner. ( private )
bool TahminOyunu::Sayi_Dizide_Var_Mi(int depoDizi[], string xlerden_OLusan_Dizi[], int tahmin, int kullanici_Eleman_Girisi)
{
	bool varMi = false;
	for (int i = 0; i < kullanici_Eleman_Girisi; i++)
	{
		if (depoDizi[i] == tahmin) // tahmin edilen say� dizide varsa
		{
			cout << tahmin << " bulundu !" << endl;
			xlerden_OLusan_Dizi[i] = to_string(tahmin); // bulunan say� g�r�n�r hale getirilir
			varMi = true;
		}
	}
	return varMi;
}

// burada da gerekli i�lemlerden sonra dizinin i�eri�i g�sterilir ( private )
void TahminOyunu::Sonuclari_Goster()
{
	for (int i = 0; i < kullanici_Eleman_Girisi; i++)
	{
		cout << xlerden_OLusan_Dizi[i] << " ";
	}
}


// kullan�c�n�n oyunu kazand��� ya da kaybetti�i belirlenir  ( private )
bool TahminOyunu::Kazan_Kaybet(int depoDizi[], int tahminDizi[], int kazanKaybet, bool kazandiMi)
{
	for (int i = 0; i < kullanici_Eleman_Girisi; i++) // ilk d�ng� rasgele say�lardan olu�an depoDizi sini temsil eder
	{
		for (int j = 0; j < oyun_Tahmin_Sayisi; j++) // ikinci d�ng� tahmin edilen say�lar�n bulundu�u tahminnDizi sini temsil eder
		{
			if (depoDizi[i] == tahminDizi[j]) // e�er tahminler rasgele �retilen say�lar�n bulundu�u depoDizisi i�inde varsa 
			{
				kazanKaybet++; // de�i�keni art�r
			}
		}
	}
	if (kazanKaybet == kullanici_Eleman_Girisi) // eger kazanKaybet de�ii�keninin de�eri depoDizisindeki elemanlar�n say�s�na e�itse
	{
		// kullan�c� oyunu kazand�
		kazandiMi = true;
		return kazandiMi;
	}
	else
	{
		// de�ilse kaybetti
		kazandiMi = false;
		return kazandiMi;
	}
}

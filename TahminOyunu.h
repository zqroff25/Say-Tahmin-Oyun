#ifndef TAHMINOYUNU_H
#define TAHMINOYUNU_H
#include <string>
#include <ctime>
using namespace std;
class TahminOyunu
{

public:
	TahminOyunu(); // yap�c� fonksiyon (constructor) 

	void OyunOyna(); 

private:
	// dizileri b�yle ba�latmam�n nedeni: diziler �nceden ba�lat�lmal� uyar�s�n� al�yor olmamd�r.
	// dizilere ilk de�erler atayarak sorunu ��zd�m.
	int depoDizi[20]{ 0, 0, 0, 0, 0 };    // 1. de�i�ken en az 2 en �ok 20 tane eleman saklayabilen bir dizi
	int tahminDizi[40]{ 0, 0, 0, 0, 0,0, 0, 0, 0, 0 };      // tahmin edilen say�lar� saklayan dizidir
	int kullanici_Eleman_Girisi = 0;  // 2. de�i�ken  kullan�c�n�n ka� say� tahmin etmek istedi�ini tutan de�i�ken
	int oyun_Tahmin_Sayisi = 0;       // 3. de�i�ken  ka� say�  tahmin edilecekse 2 kat� kadar tahmin say�s� olmal�
	int rasgele_AltLimit = 0;         // 4. de�i�ken  hhangi aral�kta rasgele say� �retilece�ini belirleyiniz
	int rasgele_UstLimit = 0;         // 5. de�i�ken
	bool elemanKontrol = false;       // kullan�c�n�n 2 ile 20 aras�nda eleman de�eri girip girmedi�ini kontrol eder
	bool tahminKontrol = false;       // tahmin edilmi� bir say�n�n �nceden de kullan�l�p kullan�lmad���n� kontrol eder
	int tahmin = 0;					  // kullan�c�n�n tahmin etti�i say� de�erini saklar
	bool tahminVarMi = true;          // tahmin edilen say�n�n rasgele �retilen say�larla dolu dizide oldu�unu kontrol eder
	bool kazandiMi = false;           // kullan�c�n�n oyunu kazan�p kazanma���n� kontrol eder
	int kazanKaybet = 0;              // do�ru tahmin edilen say�lar�n ka� adet oldu�unu saklar 
	string xlerden_OLusan_Dizi[20];   // rasgele �retilen say�alr� x ile gizlemek i�in kullan�l�r


	void Diziyi_Olustur(int[], int, int, int);             // diziyi olu�turmak i�in ayr� bir fonskiyon 
	void Xlerden_OLusan_Diziyi_Olsutur(string[], int);     // dizideki elemanlar� gizlemek i�in olu�turulan fonksiyon 
	bool Sayi_Dizide_Var_Mi(int[], string[], int, int);    // tahmin edilen say�n�n dizideki varl���n� kontrol eden fonskiyon 
	void Sonuclari_Goster();                               // i�lemler sonucunda dizinin i�eri�ini g�steren fonksiyon 
	bool Kazan_Kaybet(int[], int[], int, bool);            // oyunun kazan�ld��� ya da kaybedildi�ini belirleyen fonksiyon
};

#endif // !1
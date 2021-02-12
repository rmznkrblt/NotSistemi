#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>


int kisi = 0, secim;
FILE* dosya;

struct ogrenci {
	int ogrenciNo;
	char isim[50];
	char soyad[50];
	int vize;
	int final;
	int odev1;
	int odev2;
	int alinanNot;
};

int menu();
void kayitEkle();
void ogrenciAra();
void raporYazdir();
void anaMenuyeDon();
void veriAl();
char parametreliKayitEkle(char[]);

struct ogrenci ogrenciListesi[100];

int main(int argc, char* argv[]) {
	if (argc > 1) { //parametreyle calisan bolum
		veriAl();
		do {
			secim = menu();
			switch (secim) {
			case 1: {
				parametreliKayitEkle(argv[1]);
				anaMenuyeDon();
				break;
			}
			case 2: {
				ogrenciAra();
				anaMenuyeDon();
				break;
			}
			case 3: {
				raporYazdir();
				anaMenuyeDon();
				break;
			}
			default:
				break;
			}
		} while (secim != 0);
	}
	else { //parmetresiz calisan bolum
		do {
			secim = menu();
			switch (secim) {
			case 1: {
				kayitEkle();
				anaMenuyeDon();
				break;
			}
			case 2: {
				ogrenciAra();
				anaMenuyeDon();
				break;
			}
			case 3: {
				raporYazdir();
				anaMenuyeDon();
				break;
			}
			default:
				break;
			}
		} while (secim != 0);
	}
	return 0;
}

char parametreliKayitEkle(char dosyaAdiParam[])
{
	dosya = fopen(dosyaAdiParam, "a+");
	if (kisi <= 99) {
		int tekrarKontrolu = 1, i;
		printf("  OGRENCI BILGILERINIZI GIRINIZ");
		printf("\nOGRENCI NUMARASI:");
		scanf("%d", &ogrenciListesi[kisi].ogrenciNo);
		for (i = 0; i < kisi; i++)
			if (ogrenciListesi[kisi].ogrenciNo == ogrenciListesi[i].ogrenciNo)
				tekrarKontrolu = 0;
		if (tekrarKontrolu)
		{
			printf("ISIM:");
			scanf("%s", &ogrenciListesi[kisi].isim);
			printf("SOYAD:");
			scanf("%s", &ogrenciListesi[kisi].soyad);
			printf("VIZE SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].vize);
			printf("FINAL SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].final);
			printf("ODEV1 SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].odev1);
			printf("ODEV2 SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].odev2);
			fprintf(dosya, "\n%d %s %s %d %d %d %d", ogrenciListesi[kisi].ogrenciNo, ogrenciListesi[kisi].isim, ogrenciListesi[kisi].soyad, ogrenciListesi[kisi].vize, ogrenciListesi[kisi].final, ogrenciListesi[kisi].odev1, ogrenciListesi[kisi].odev2);
			fclose(dosya);
			ogrenciListesi[kisi].alinanNot = round(ogrenciListesi[kisi].vize * 0.25 + ogrenciListesi[kisi].final * 0.4 + ogrenciListesi[kisi].odev1 * 0.15 + ogrenciListesi[kisi].odev2 * 0.2);
			kisi += 1;
		}
		else
			printf("Sistemde bu numarada kayit mevcut...");

	}
	else
		printf("\nDizi dolu!\n");
}

void veriAl() {
	dosya = fopen("ogrenciListesi.txt", "r");
	if (dosya != NULL)
		while (!feof(dosya))
		{
			fscanf(dosya, "%d %s %s %d %d %d %d", &ogrenciListesi[kisi].ogrenciNo, &ogrenciListesi[kisi].isim, &ogrenciListesi[kisi].soyad, &ogrenciListesi[kisi].vize, &ogrenciListesi[kisi].final, &ogrenciListesi[kisi].odev1, &ogrenciListesi[kisi].odev2);
			ogrenciListesi[kisi].alinanNot = round(ogrenciListesi[kisi].vize * 0.25 + ogrenciListesi[kisi].final * 0.4 + ogrenciListesi[kisi].odev1 * 0.15 + ogrenciListesi[kisi].odev2 * 0.2);
			kisi += 1;
		}
	else
		printf("Dosya Bulunamadi...\n");
}

int menu() {
	int secim;
	printf("\n             MENU\n");
	printf("_______________________________\n");
	printf("1) OGRENCI EKLEME\n");
	printf("2) OGRENCI ARAMA(NUMARA ILE)\n");
	printf("3) RAPOR YAZDIR\n");
	scanf("%d", &secim);
	system("cls");
	return 	secim;
}



void kayitEkle() {
	if (kisi <= 99) {
		printf("  OGRENCI BILGILERINIZI GIRINIZ");
		printf("\nOGRENCI NUMARASI:");
		scanf("%d", &ogrenciListesi[kisi].ogrenciNo);

		int tekrarKontrolu = 1, i;

		for (i = 0; i < kisi; i++)
			if (ogrenciListesi[kisi].ogrenciNo == ogrenciListesi[i].ogrenciNo)
				tekrarKontrolu = 0;
		if (tekrarKontrolu)
		{
			printf("ISIM:");
			scanf("%s", &ogrenciListesi[kisi].isim);
			printf("SOYAD:");
			scanf("%s", &ogrenciListesi[kisi].soyad);
			printf("VIZE SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].vize);
			printf("FINAL SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].final);
			printf("ODEV1 SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].odev1);
			printf("ODEV2 SONUCU:");
			scanf("%d", &ogrenciListesi[kisi].odev2);
			ogrenciListesi[kisi].alinanNot = round(ogrenciListesi[kisi].vize * 0.25 + ogrenciListesi[kisi].final * 0.4 + ogrenciListesi[kisi].odev1 * 0.15 + ogrenciListesi[kisi].odev2 * 0.2);
			kisi += 1;
		}
		else
			printf("Sistemde bu numarada kayit mevcut...");

	}
	else
		printf("\nDizi dolu!\n");
}

void anaMenuyeDon()
{
	printf("\n\nAna menuye donmek icin 'M' tusuna basiniz...\n");
	char m;
	scanf(" %c", &m);
	if (m == 'M' || m == 'm')
		system("cls");
	else
		secim = 0;

}

void ogrenciAra() {
	int i;
	int mevcut = -1;
	if (kisi == 0)
		printf("\nListe bos!\n");
	else {
		printf("ARANACAK OGRENCI NUMARASINI GIRINIZ:");
		int numara;
		scanf("%d", &numara);
		for (i = 0; i <= kisi; i++) {
			if (ogrenciListesi[i].ogrenciNo == numara) {
				mevcut = 1;
				printf("\nOGRENCI NUMARASI : %d", ogrenciListesi[i].ogrenciNo);
				printf("\nISIM : %s", ogrenciListesi[i].isim);
				printf("\nSOYAD : %s", ogrenciListesi[i].soyad);
				printf("\nVIZE SONUCU : %d", ogrenciListesi[i].vize);
				printf("\nFINAL SONUCU : %d", ogrenciListesi[i].final);
				printf("\nODEV1 SONUCU : %d", ogrenciListesi[i].odev1);
				printf("\nODEV2 SONUCU : %d", ogrenciListesi[i].odev2);
				printf("\nDONEM SONU NOTU : %d\n\n", ogrenciListesi[i].alinanNot);
				break;
			}
		}
		if (mevcut == -1)
			printf("\nKAYIT BULUNAMADI\n");
	}
}

void raporYazdir() {
	int i;
	if (kisi == 0) {
		printf("\nListe bos!\n");
	}
	else {
		float vizeOrt = 0, finalOrt = 0, odev1Ort = 0, odev2Ort = 0, notOrt = 0;
		for (i = 0; i < kisi; i++)
			if (ogrenciListesi[i].ogrenciNo != 0 && strcmp(ogrenciListesi[i].isim, " ") != 0 && strcmp(ogrenciListesi[i].soyad, " ") != 0)
			{
				vizeOrt += ogrenciListesi[i].vize;
				finalOrt += ogrenciListesi[i].final;
				odev1Ort += ogrenciListesi[i].odev1;
				odev2Ort += ogrenciListesi[i].odev2;
				notOrt += ogrenciListesi[i].alinanNot;
			}
		dosya = fopen("DersRaporu.txt", "w");
		if (dosya != NULL)
		{
			fprintf(dosya,
				"Toplam Ogrenci Sayisi = %d\n\n"
				"Vize Ortalamasi = %.2f\n"
				"Final Ortalamasi = %.2f\n"
				"Odev1 Ortalamasi = %.2f\n"
				"Odev2 Ortalamasi = %.2f\n"
				"Donem Sonu Not Ortalamasi = %.2f\n", kisi, vizeOrt / kisi, finalOrt / kisi, odev1Ort / kisi, odev2Ort / kisi, notOrt / kisi);
			fclose(dosya);
			printf("\nRAPOR YAZDIRILDI...\n");
		}
		else
			printf("Dosya Bulunamadi...\n");
	}
}



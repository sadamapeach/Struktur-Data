/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : *24060121130060/ Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 29 Agustus 2022*/
/***********************************/
#include <stdio.h>
#include "titik.h"

int main() {
	/*kamus*/
	int absis, ordinat;
	int K;
	int J;
	Titik P;
	
	/*algoritma*/
	printf("===== Praktikum 01 ADT Titik =====\n\n");
	
	/*Soal 1 makeTitik*/
	makeTitik(&P);
	printf("1. Make Titik\n");
	printf("   - Titik absis\t= %d\n", P.absis);   
	printf("   - Titik ordinat\t= %d\n", P.ordinat);
	
	/*Soal 2 Get Absis dan Ordinat*/
	P.absis     = 4;
	P.ordinat   = 3;
	absis       = getAbsis(P);
	ordinat     = getOrdinat(P); 
	printf("\n2. Get Absis dan Ordinat\n");
	printf("   - Get absis\t\t= %d\n",absis);
	printf("   - Get ordinat\t= %d\n",ordinat);
	
	/*Soal 3 Set Absis dan Ordinat*/
	printf("\n3. Set Absis dan Ordinat\n");
	setAbsis(&P, 5);
	printf("   - Set absis\t\t= %d\n",P.absis);
	setOrdinat(&P, 7);
	printf("   - Set ordinat\t= %d\n",P.ordinat);
	
	/*Soal 4 Is Origin*/
	printf("\n4. Is Origin?");
	if(isOrigin(P)) {
	    printf("\n   Titik 0,0");
	} else {
	    printf("\n   Bukan titik origin.\n");
	}
	
	/*Soal 5 Geser X dan Y*/
	geserXY(&P, 10, 15);
	printf("\n5. Geser Absis dan Ordinat\n");
	printf("   - Absis\t= %d\n   - Ordinat\t= %d\n", P.absis, P.ordinat);
	
	/*Soal 6 Refleksi Sumbu X dan Y*/
	printf("\n6. Refleksi Sumbu X dan Y\n");
	refleksiSumbuX(&P);
	printf("   - Sumbu x = %d\n", P.ordinat);
	refleksiSumbuY(&P);
	printf("   - Sumbu y = %d\n", P.absis);
	
	/*Soal 7 Kuadran*/
    K = Kuadran(P);
    printf("\n7. Kuadran\n");
	printf("   Titik terletak pada kuadran %d.\n", K);
	
	/*Soal 8 Jarak*/
	J = Jarak(P);
	printf("\n8. Jarak Titik\n");
	printf("   Jarak = %d", J);
	
	return 0;
}
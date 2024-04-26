/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : *24060121130060/ oktaviana Sadama Nur Azizah*/
/* Tanggal   : 29 Agustus 2022*/
/***********************************/
#include <stdio.h>
#include "titik.h"

/*print doang*/
int main() {
	/*kamus*/
	int absis, ordinat;
	int K;
	int J;
	Titik P;
	
	/*algoritma*/
	makeTitik(&P);
	printf("Titik absis\t= %d\nTitik ordinat\t= %d", P.absis, P.ordinat);
	
	P.absis = 4;
	absis = getAbsis(P); /*perintah melakukan fungsi*/
	printf("\n\nNilai absis\t= %d",absis);
	
	P.ordinat = 3;
	ordinat = getOrdinat(P); 
	printf("\nNilai ordinat\t= %d",ordinat);
	
	setAbsis(&P, 5);
	printf("\n\nNilai absis baru\t= %d",P.absis);
	
	setOrdinat(&P, 7);
	printf("\nNilai ordinat baru\t= %d",P.ordinat);
	
	if(isOrigin(P)) {
	    printf("\ntitik 0,0");
	} else {
	    printf("\n\nbukan titik origin");
	}
	
	geserXY(&P, 10, 15);
	printf("\n\nT.absis\t\t= %d\nT.ordinat\t= %d", P.absis, P.ordinat);
	
	refleksiSumbuX(&P);
	printf("\n\nRefleksi sumbu x = %d", P.ordinat);
	
	refleksiSumbuY(&P);
	printf("\nRefleksi sumbu Y = %d", P.absis);
	
    K = Kuadran(P);
	printf("\n\nTitik terletak pada kuadran %d", K);
	
	J = Jarak(P);
	printf("\n\nJarak = %d", J);
	
	return 0;
}
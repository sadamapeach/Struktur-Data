/* Program   : main.c */
/* Deskripsi : driver file modul ADT Matriks */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 12 September 2022*/
/***********************************/
#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

int main() {
	/*kamus*/
	Matriks A;
	int x;
	int bar;
	int kol;
	
	/*algoritma*/
	printf("========================== MATRIKS ==========================\n");

	makeMatriks(&A);
	setNbbar(&A,3);
    setNbkol(&A,4);
    printf("Original matriks yang sudah di set banyak baris dan kolommnya\n");
    printMatriks(A);
    printf("Banyak baris = %d\n", getNbbar(A));
	printf("Banyak kolom = %d\n", getNbkol(A));
	printf("\n");
	
	printf("getInfoCell\n");
	A.wadah[1][1] = 100;
	x = getInfoCell(A,1,1);
	printMatriks(A);
	printf("Isi elemen pada baris 1, kolom 1 matriks adalah %d.\n", x);
	printf("\n");
	
	printf("setInfoCell\n");
	setInfoCell(&A, 2, 1, 200);
	setInfoCell(&A, 3, 1, 300);
	printMatriks(A);
	
	printf("\nBoolean\n");
	printf("1 = True | 0 = False\n");
	printf("Apakah matriks kosong? %d\n", isEmptyMatriks(A));
	printf("Apakah matriks penuh? %d\n", isFullMatriks(A));
	printf("\n");
	
	printf("Print Matriks\n");
	printMatriks(A);
	printf("\n");
	printf("View Matriks\n");
	viewMatriks(A);
	printf("\n");
	
	printf("Operasi Matriks\n");
	printf("Sum\t= %d\n", sumCellMatriks(A));
	printf("Average\t= %.2f\n", avgCellMatriks(A));
	printf("Max\t= %d\n", maxCellMatriks(A));
	printf("Min\t= %d\n", minCellMatriks(A));
	printf("Count 1\t= %d\n", countA(A, 1));
	printf("\n");
	
	printf("Search Matriks\n");
	searchMatriks(A, 200, &bar, &kol);
	printf("\n");
	
	printf("Transpose Matriks\n");
	transpose(&A);
	printMatriks(A);
	
	printf("\nAlhamdulillah selesai :)");
	
	return 0;
}
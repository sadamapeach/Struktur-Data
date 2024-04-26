/* Program   : main.c */
/* Deskripsi : file DRIVER modul list Ganda */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah */
/* Tanggal   : 24 November 2022 */
/**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

int main() {
    /* kamus main */
    List T;
    address A, B, C, D, E;
    infotype A1, B1, C1, D1, E1; 
    address A2, B2, C2, D2, E2; // delete
    
    /* algoritma */
    /* nilai infotype */
    A1 = 10;
    B1 = 20;
    C1 = 30;
    D1 = 40;
    E1 = 50;
    
    /* address nilai */
    A = Alokasi(A1);
    B = Alokasi(B1);
    C = Alokasi(C1);
    D = Alokasi(D1);
    E = Alokasi(E1);
    
    CreateList(&T);
    
    printf("Nama  : Oktaviana Sadama Nur Azizah\n");
    printf("NIM   : 24060121130060\n");
    printf("Kelas : A\n");
    printf("============ LIST GANDA LINIER ============\n");
    
    printf("List T = ");
    PrintInfo(T);
    
    printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah List T kosong? %d\n", ListEmpty(T));
    
    printf("\nInsert First\n");
	InsertFirst (&T, D);
	InsertFirst (&T, B);
	InsertFirst (&T, A);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert After\n");
	printf("Menginsert nilai 30 setelah nilai 20.\n");
	InsertAfter(&T, C, B);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert Last\n");
	InsertLast (&T, E);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete First\n");
	DelFirst (&T, &A2);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete Last\n");
	DelLast (&T, &E2);
	printf("List T = ");
	PrintInfo(T); 
	
	printf("\nDelete After\n");
	printf("Menghapus nilai 30 setelah nilai 20.\n");
    DelAfter (&T, &C, B);
	printf("List T = ");
	PrintInfo(T);
    
    printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah List T kosong? %d\n", ListEmpty(T));
    
    return 0;
}
/* Program   : main.c */
/* Deskripsi : file DRIVER modul list */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 24 Oktober 2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    /* kamus main */
    List T;
    address A, B, C, D, E, Q, R, AB, BC;
    /* {A, B, C, D, E mengalokasikan nilai}
       {Q, R mengalokasikan infotype} */
    infotype G, H, I, X, Y; // X dan Y sebagai wadah atau keranjang
    
    /* algoritma */
    /* nilai infotype */
    G = 45;
    H = 20;
    I = 16;
    
    /* address nilai */
    A = Alokasi(3);
    B = Alokasi(28);
    C = Alokasi(45);
    D = Alokasi(89);
    E = Alokasi(16);
    
    /* address merujuk infotype */
    Q = Alokasi(G);
    R = Alokasi(H);
    
    CreateList(&T);
    
    printf("=============== LIST ===============");
    printf("\n");
    
    printf("List = ");
    PrintInfo(T);
    
    printf("\nBoolean\n");
	printf("1 = true | 0 = false\n");
	printf("Apakah List T kosong? %d\n", ListEmpty(T));
	
	printf("\nInsert First\n");
	InsertFirst (&T, E);
	InsertFirst (&T, C);
	InsertFirst (&T, A);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert After\n");
	printf("Menginsert nilai 89 setelah nilai 45.\n");
	InsertAfter(&T, D, C);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert Last\n");
	InsertLast (&T, B);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete First\n");
	DelFirst (&T, &AB);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete Last\n");
	DelLast (&T, &BC);
	printf("List T = ");
	PrintInfo(T); 
	
	printf("\nDelete After\n");
	printf("Menghapus nilai 89 yang berada setelah nilai 45.\n");
    DelAfter (&T, &D, C);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert V First\n");
	InsVFirst(&T, 15); 
	printf("List T = ");
	PrintInfo(T);
	InsVFirst(&T, 7);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert V Last\n");
	InsVLast(&T, 92); 
	printf("List T = ");
	PrintInfo(T);
	InsVLast(&T, 71); 
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nInsert V After\n");
	printf("Menginsert nilai 20 setelah nilai 45.\n");
	InsVAfter(&T, 20, G);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete V First\n");
    DelVFirst(&T, &X);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete V Last\n");
    DelVLast(&T, &Y);
	printf("List T = ");
	PrintInfo(T);
	
	printf("\nDelete V After\n");
	printf("Menghapus nilai 16 yang berada setelah nilai 20.\n");
	DelVAfter(&T, &I, H);
	printf("List T = ");
	PrintInfo(T);

    printf("\nNbElmt\n");
    printf("Banyak elemen list = %d", NbElmt(T));
    
    return 0;
}
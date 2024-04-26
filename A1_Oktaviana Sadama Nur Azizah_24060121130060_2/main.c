/* Program   : main.c */
/* Deskripsi : file DRIVER modul list */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 07 November 2022*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
    /* kamus main */
    List T, T1, T2, T3, L, New;
    address A, B, C, D, E, F, Q, R, S, O;
    address AB, BC, SC1;
    /* {AB, BC address delete} */
    infotype G, H, I, J, K, X, Y; 
    /* X dan Y sebagai wadah delete */
    
    /* algoritma */
    /* nilai infotype */
    G = 71;
    H = 20;
    I = 16;
    J = 92;
    K = 7;
    
    /* address nilai */
    A = Alokasi(3);
    B = Alokasi(28);
    C = Alokasi(45);
    D = Alokasi(89);
    E = Alokasi(16);
    F = Alokasi(15);
    
    /* address merujuk infotype */
    Q = Alokasi(G);
    R = Alokasi(H);
    S = Alokasi(J);
    O = Alokasi(K);
    
    CreateList(&T);
    
    printf("============ LIST LINIER BAG.1 ============");
    printf("\n");
    
    printf("List T = ");
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
	InsVAfter(&T, 20, 45);
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
	DelVAfter(&T, &I, 20);
	printf("List T = ");
	PrintInfo(T);

    printf("\nNbElmt\n");
    printf("Banyak elemen list = %d", NbElmt(T));
    printf("\n");

    printf("\n");    
    printf("============ LIST LINIER BAG.2 ============");
    
    printf("\nList T = ");
	PrintInfo(T);
	
    printf("\nSearch\n");
    SC1 = Search(T, 20);
    if (SC1 == Nil) {
        printf("!Elemen tidak ditemukan!\n");
    } else {
        printf("Address elemen %d = %x\n", info(R), info(SC1));
    }
    
    printf("\nFSearch\n");
    printf("Apakah elemen %d terdapat dalam List T?\n", info(C));
    if (FSearch(T, C) == false) {
        printf("!Elemen tidak ditemukan! False!\n");
    } else {
        printf("!Elemen ditemukan! True!\n");
    }
    
    printf("\nSearchPrec\n");
    printf("Nilai address sebelum elemen %d = %d\n", info(C), info(SearchPrec(T,45)));
    
    printf("\nInvers List\n");
    InversList(&T);
    printf("List T = ");
    PrintInfo(T);
    
    printf("\nFInvers List\n");
    printf("Invers elemen List T ke List New\n");
    New = FInversList(T);
    printf("List New = ");
    PrintInfo(New);
    
    printf("\nCopy List T ke List L1\n");
    CreateList(&L);
    CopyList(&T, &L);
    printf("List L1 = ");
    PrintInfo(L);
    
    printf("\nFCopy List New ke List L2\n");
    FCopyList(New);
    printf("List L2 = ");
    PrintInfo(New);
    
    printf("\nPecah List\n");
    printf("List T = ");
    PrintInfo(T);
    printf("------- list dipecah -------\n");
    PecahList(&T1, &T2, T);
    printf("List T1 = ");
    PrintInfo(T1);
    printf("List T2 = ");
    PrintInfo(T2);
    
    printf("\nKonkat\n");
    printf("---------- Kondisi Awal ----------\n");
    printf("List T1 = ");
    PrintInfo(T1);
    printf("List T2 = ");
    PrintInfo(T2);
    printf("-------- Konkat T1 dan T2 --------\n");
    Konkat(T1, T2, &T3);
    printf("List T3 = ");
    PrintInfo(T3);
    printf("---------- Kondisi Akhir ---------\n");
    printf("--- !TANPA MENGHAPUS T1 DAN T2! --\n");
    printf("List T1 = ");
    PrintInfo(T1);
    printf("List T2 = ");
    PrintInfo(T2);
    
    printf("\nKonkat 1\n");
    printf("---------- Kondisi Awal ----------\n");
    printf("List T1 = ");
    PrintInfo(T1);
    printf("List T2 = ");
    PrintInfo(T2);
    printf("-------- Konkat T1 dan T2 --------\n");
    Konkat1 (&T1, &T2, &T3);
    printf("List T3 = ");
    PrintInfo(T3);
    printf("---------- Kondisi Akhir ---------\n");
    printf("------ !MENGHAPUS T1 DAN T2! -----\n");
    printf("List T1 = ");
    PrintInfo(T1);
    printf("List T2 = ");
    PrintInfo(T2);
    
    printf("\nDelete All\n");
    printf("List T = ");
    PrintInfo(T);
    printf("Delete = ");
    DelAll(&T);
    PrintInfo(T);
    
    return 0;
}
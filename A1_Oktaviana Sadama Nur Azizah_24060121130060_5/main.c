/* Program   : main.c */
/* Deskripsi : file DRIVER modul Pohon Biner */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah */
/* Tanggal   : 28 November 2022 */
/**********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "PohonBiner.h"

int main() {
    /*kamus main*/
    BinTree T1, T2, T3, T4, T5, B;
    
    /*algoritma*/
    printf("Nama  : Oktaviana Sadama Nur Azizah\n");
    printf("NIM   : 24060121130060\n");
    printf("Kelas : A\n");
    printf("============ BINARY TREE ============\n");
    
    /* --------------------- Binary Tree --------------------- */
    // Empty Binary Tree 
    T1 = Nil;
    
    // Tree
    T2 = Tree(10, Nil, Nil); //satu elemen (akar)
    T3 = Tree(10, Tree(2,Nil,Nil), Tree(17,Nil,Nil)); //biner
    
    // MakeTree
    MakeTree(15, Tree(4,Nil,Nil), Nil, &T4); //uner left
    MakeTree(20, Nil, Tree(25,Nil,Nil), &T5); //uner right
    
    /* --------------------- PrintTreeL --------------------- */
    printf("Print Binary Tree L [ver.1]\n");
    printf("Print T1 : ");
    PrintTreeL(T1, 5, 3);
    
    printf("Print T2 : \n");
    PrintTreeL(T2, 5, 3);
    
    printf("Print T3 : \n");
    PrintTreeL(T3, 5, 3);
    
    printf("Print T4 : \n");
    PrintTreeL(T4, 5, 3);

    printf("Print T5 : \n");
    PrintTreeL(T5, 5, 3);
    
    /* --------------------- PrintTree --------------------- */
    printf("\nPrint Binary Tree [ver.2]\n");
    printf("Print T1 : ");
    PrintTree(T1, 5);
    
    printf("Print T2 : \n");
    PrintTree(T2, 5);
    
    printf("Print T3 : \n");
    PrintTree(T3, 5);
    
    printf("Print T4 : \n");
    PrintTree(T4, 5);

    printf("Print T5 : \n");
    PrintTree(T5, 5);
    
    /* --------------------- isTreeEmpty --------------------- */
    printf("\nIs Tree Empty? {1 = true | 0 = false}\n");
    printf("- Tree T1? %d\n", isTreeEmpty(T1));
    
    printf("- Tree T2? %d\n", isTreeEmpty(T2));
    
    printf("- Tree T3? %d\n", isTreeEmpty(T3));
    
    printf("- Tree T4? %d\n", isTreeEmpty(T4));
    
    printf("- Tree T5? %d\n", isTreeEmpty(T5));
    
    /* --------------------- isOneElmt --------------------- */
    printf("\nIs One Element? {1 = true | 0 = false}\n");
    printf("- Tree T1? %d\n", isOneElmt(T1));
    
    printf("- Tree T2? %d\n", isOneElmt(T2));
    
    printf("- Tree T3? %d\n", isOneElmt(T3));
    
    printf("- Tree T4? %d\n", isOneElmt(T4));
    
    printf("- Tree T5? %d\n", isOneElmt(T5));
    
    /* --------------------- isUnerLeft --------------------- */
    printf("\nIs Uner Left? {1 = true | 0 = false}\n");
    printf("- Tree T1? %d\n", isUnerLeft(T1));

    printf("- Tree T2? %d\n", isUnerLeft(T2));
    
    printf("- Tree T3? %d\n", isUnerLeft(T3));
    
    printf("- Tree T4? %d\n", isUnerLeft(T4));
    
    printf("- Tree T5? %d\n", isUnerLeft(T5));
    
    /* --------------------- isUnerRight --------------------- */
    printf("\nIs Uner Right? {1 = true | 0 = false}\n");
    printf("- Tree T1? %d\n", isUnerRight(T1));

    printf("- Tree T2? %d\n", isUnerRight(T2));
    
    printf("- Tree T3? %d\n", isUnerRight(T3));
    
    printf("- Tree T4? %d\n", isUnerRight(T4));
    
    printf("- Tree T5? %d\n", isUnerRight(T5));
    
    /* --------------------- isBiner --------------------- */
    printf("\nIs Biner? {1 = true | 0 = false}\n");
    printf("- Tree T1? %d\n", isBiner(T1));

    printf("- Tree T2? %d\n", isBiner(T2));
    
    printf("- Tree T3? %d\n", isBiner(T3));
    
    printf("- Tree T4? %d\n", isBiner(T4));
    
    printf("- Tree T5? %d\n", isBiner(T5));
    
    /* --------------------- New Tree --------------------- */ 
    printf("\nNew Tree\n");
    MakeTree(15, Tree(10,Tree(7,Nil,Nil),Tree(12,Nil,Nil)), Tree(20,Tree(18,Nil,Nil),Nil), &B);
    printf("Print B : \n");
    PrintTreeL(B, 5, 3);
    
    /* --------------------- PrintPreOrder --------------------- */
	printf("Print Pre Order  : ");
	PrintPreOrder(B);

	printf("\nPrint In Order   : ");
	PrintInOrder(B);

	printf("\nPrint Post Order : ");
	PrintPostOrder(B);
	
    return 0;
}
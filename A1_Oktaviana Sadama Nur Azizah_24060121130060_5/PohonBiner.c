/* Program   : PohonBiner.c */
/* Deskripsi : file BODY modul Pohon Biner */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah */
/* Tanggal   : 28 November 2022 */
/***********************************/

#include <stdio.h>
#include "PohonBiner.h"
#ifndef PohonBiner_c

/* Mengirimkan address hasil alokasi sebuah elemen X */
/* Jika alokasi berhasil, maka address tidak nil, 
  dan misalnya menghasilkan P, maka 
  Info(P) = X, Left(P) = Nil, Right(P) = Nil
  Jika alokasi gagal, mengirimkan Nil */
address Alokasi (int X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    P = (address)malloc(sizeof(Node));
    if(P!=Nil) {
        Akar(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    } return P;
}

/* Melakukan dealokasi / pengembalian address P */
/* I.S.     : P terdefinisi  
   F.S.     : P dikembalikan ke sistem */
void Dealokasi(address P) {
    /*kamus lokal*/
    /*algoritma*/
    free(P);
}

/* Menghasilkan sebuah pohon biner dari A, L, dan R, 
  jika alokasi berhasil.
  Menghasilkan pohon kosong (Nil) jika alokasi gagal */
BinTree Tree(infotype Akar, BinTree L, BinTree R) {
    /*kamus lokal*/
    BinTree P;
    
    /*algoritma*/
    P = Alokasi(Akar);
    if(P!=Nil) {
        Akar(P) = Akar;
        Left(P) = L;
        Right(P) = R;
    } return P;
}

/* Menghasilkan sebuah pohon biner P dari A, L, dan R, 
  jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
/* I.S.     : Sembarang 
   F.S.     : Menghasilkan sebuah pohon P */
void MakeTree(infotype Akar, BinTree L, BinTree R, BinTree *P) {
    /*kamus lokal*/
    /*algoritma*/
    (*P) = Alokasi(Akar);
    if((*P)!=Nil) {
        Akar((*P)) = Akar;
        Left((*P)) = L;
        Right((*P)) = R;
    }
}

/* ----- Predikat-Predikat Penting ----- */

/* Mengirimkan true jika P adalah pohon biner yang kosong */
boolean isTreeEmpty(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    return (P == Nil);
}

/* Mengirimkan true jika P tidak kosong dan hanya terdiri atas 1
  elemen */
boolean isOneElmt(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    return ((!isTreeEmpty(P)) && (isTreeEmpty(Left(P))) && (isTreeEmpty(Right(P))));
}

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon
  unerleft: hanya mempunyai subpohon kiri */
boolean isUnerLeft(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    return ((!isTreeEmpty(P)) && (Right(P) == Nil) && (Left(P) != Nil));
}

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon
  unerright: hanya mempunyai subpohon kanan */
boolean isUnerRight(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    return ((!isTreeEmpty(P)) && (Right(P) != Nil) && (Left(P) == Nil));
}

/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon
  biner: mempunyai subpohon kiri dan subpohon kanan */
boolean isBiner(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    return ((!isTreeEmpty(P)) && (Right(P) != Nil) && (Left(P) != Nil));
}

/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* I.S.     : P terdefinisi, h adalah jarak indentasi (spasi)
   F.S.     : Semua simpul P sudah ditulis dengan indentasi (spasi) */
void PrintTreeL(BinTree P, int h, int CLevel) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    if(!isTreeEmpty(P)) {
        for(i=1; i<=h*(CLevel-1); i++) {
            printf(" ");
        } printf("%d\n", Akar(P));
        
        if(Left(P)!=Nil) {
            PrintTreeL(Left(P), h, CLevel+1);
        } 
        if(Right(P)!=Nil) {
            PrintTreeL(Right(P), h, CLevel+1);
        } 
    } else {
        printf("[!Tree Empty!]\n");
    }
}

/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* I.S.     : P terdefinisi, h adalah jarak indentasi (spasi)
   F.S.     : Semua simpul P sudah ditulis dengan indentasi (spasi) */
void PrintTree(BinTree P, int h) {
    /*kamus lokal*/
    /*algoritma*/
    PrintTreeL(P,h,1);
}

/* Basis    : Pohon kosong; tidak ada yang diproses */
/* Rekurens : Cetak Akar(P); cetak secara Preorder (Left(P)); cetak
              secara Preorder (Right(P)) */
/* I.S.     : Pohon P terdefinisi 
  F.S.     : Semua node pohon P sudah dicetak secara PreOrder: akar, 
              kiri, kanan */
void PrintPreOrder(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isTreeEmpty(P)) {
        printf("%d |", Akar(P));
        PrintPreOrder(Left(P));
        PrintPreOrder(Right(P));
    } 
}

/* Basis    : Pohon kosong; tidak ada yang diproses */
/* Rekurens : cetak secara Preorder (Left(P)); Cetak Akar(P); cetak
              secara Preorder (Right(P)) */ 
/* I.S.     : Pohon P terdefinisi 
  F.S.     : Semua node pohon P sudah dicetak secara PreOrder: akar, 
              kiri, kanan */
void PrintInOrder(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isTreeEmpty(P)) {
        PrintPreOrder(Left(P));
        printf("%d |", Akar(P));
        PrintPreOrder(Right(P));
    }   
}

/* Basis    : Pohon kosong; tidak ada yang diproses */
/* Rekurens : cetak secara Preorder (Left(P)); cetak secara Preorder
              (Right(P)); Cetak Akar(P) */
/* I.S.     : Pohon P terdefinisi */
/* F.S.     : Semua node pohon P sudah dicetak secara PreOrder: akar, 
              kiri, kanan */
void PrintPostOrder(BinTree P) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isTreeEmpty(P)) {
        PrintPreOrder(Left(P));
        PrintPreOrder(Right(P));
        printf("%d |", Akar(P));
    }
}

#endif

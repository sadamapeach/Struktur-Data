/* Program   : listDouble.c */
/* Deskripsi : file BODY modul list Ganda*/
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 24 November 2022*/
/***********************************/

#ifndef listGanda_C
#define listGanda_C
#include <stdio.h>
#include <stdlib.h>
#include "listDouble.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
/* Mengirim true jika list kosong */
boolean ListEmpty (List L) {
    /*kamus lokal*/
    /*algoritma*/
    return (First(L) == Nil);
}

/* ----- Pembuatan List Kosong ----- */
/* I.S.		: sembarang
  F.S.		: Terbentuk list kosong */
void CreateList (List *L) {
    /*kamus lokal*/
    /*algoritma*/
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
  dan misalnya menghasilkan P, maka
  Info(P) = X, Next(P) = Nil
  Jika alokasi gagal, mengirimkan Nil */
address Alokasi (infotype X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if (P!=Nil) {
        info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    } return P;
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P) {
    /*kamus lokal*/
    /*algoritma*/
    if(ListEmpty(*L)) {
        First(*L) = P;
    } else {
        next(P) = First(*L);
        prev(First(*L)) = P;
        First(*L) = P;
    } 
}

/* I.S.	    : Prec pastilah elemen list dan bukan elemen terakhir,
		      P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec) {
    /*kamus lokal*/
    /*algoritma*/
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    prev(P) = Prec;
    next(Prec) = P;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P) {
    /*kamus lokal*/
    address Last; // mencari last
    
    /*algoritma*/
    if(!ListEmpty(*L)) {
        Last = First(*L);
        while(next(Last)!=Nil) {
            Last = next(Last);
        } 
        prev(P) = Last;
        next(Last) = P;
        Last = P;
    } else {
        InsertFirst(L,P);
    }
}

/* Penghapusan Sebuah Elemen */
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
void DelFirst (List *L, address *P) {
    /*kamus lokal*/
    /*algoritma*/
    if(next(First(*L)) == Nil) { //kondisi satu elemen
        First(*L) = Nil;
    } else {
        (*P) = First(*L);
        First(*L) = next(First(*L));
        prev(First(*L)) = Nil;
    }
}

/* I.S.     : List tidak kosong
  F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P) {
    /*kamus lokal*/
    address Last, prevLast;
    
    /*algoritma*/
    if(prevLast == Nil) { //kondisi satu elemen (Last)
        First(*L) = Nil;
    } else {
        Last = First(*L);
        prevLast = Nil;
        while(next(Last)!=Nil) {
            prevLast = Last;
            Last = next(Last);
        }
        (*P) = Last;
        next(prevLast) = Nil;
    }
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
  F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus*/
void DelAfter (List *L, address *Pdel, address Prec) {
    /*kamus lokal*/
    /*algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    if (next(Prec)!=Nil) { //Jika elemen yang dihapus bukan elemen terakhir
        prev(next(Prec)) = Prec;
    }
    next(*Pdel) = Nil;
    prev(*Pdel) = Nil;
}

/* ----- Proses Semua Elemen List ----- */
/* I.S.     : List mungkin kosong
  F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */
void PrintInfo (List L) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    if(ListEmpty(L)) {
        printf("[!List Kosong!]");
    } else {
        P = First(L);
        while(P!=Nil) {
            printf("%d | ", info(P));
            P = next(P);
        }
    } printf("\n");
}

#endif
     
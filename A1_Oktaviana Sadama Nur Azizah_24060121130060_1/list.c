/* Program   : list.c */
/* Deskripsi : file BODY modul list */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 24 Oktober 2022*/
/***********************************/

#ifndef list_C 
#define list_C 
#include "list.h"

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
    } return P;
} 

/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
void Dealokasi (address *P) {
    /*kamus lokal*/
    /*algoritma*/
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P) {
    /*kamus lokal*/
    /*algoritma*/
    next(P) = First(*L);
    First(*L) = P;
}

/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertAfter (List *L, address P, address Prec) {
    /*kamus lokal*/
    /*algoritma*/
    next(P) = next(Prec);
    next(Prec) = P;
}

/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
void InsertLast (List *L, address P) {
    /*kamus lokal*/
    address Last;
    
    /*algoritma*/
    if(First(*L)==Nil) {
        InsertFirst(L,P);
    } else {
        Last = First(*L);
        while (next(Last)!=Nil) {
            Last = next(Last);
        } InsertAfter(L,P,Last);
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
    (*P) = First(*L);
    First(*L) = next(First(*L));
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P) {
    /*kamus lokal*/
    address Last;
    address PrecLast;
    
    /*algoritma*/
    Last = First(*L);
    PrecLast = Nil;
    while (next(Last)!=Nil) {
        PrecLast = Last;
        Last = next(Last);
    } (*P) = Last;
    if(PrecLast==Nil) {
        First(*L) = Nil;
    } else {
        next(PrecLast) = Nil;
    }
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List *L, address * Pdel, address Prec) {
    /*kamus lokal*/
    /*algoritma*/
    (*Pdel) = next(Prec);
    next(Prec) = next(next(Prec));
    next(*Pdel) = Nil;
}

/* ----- Primitif Berdasarkan Nilai ----- */
/* Penambahan Elemen */
/* I.S.		: L mungkin kosong
   F.S. 	: X ditambahkan sebagai elemen pertama L
   Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen
   			  pertama dengan nilai X jika alokasi berhasil.
   			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVFirst (List *L, infotype X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    P = Alokasi(X);
    if(P!=Nil) {
        next(P) = First(*L);
        First(*L) = P;
    }
}

/* I.S. 	: L mungkin kosong
  F.S.		: X ditambahkan sebagai elemen terakhir L
  Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
  			  di akhir yaitu
  			  jika alokasi berhasil, elemen terakhir yang baru bernilai X
  			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVLast (List *L, infotype X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    P = Alokasi(X);
    if(P!=Nil) {
        InsertLast(L,P);
    }
}

/* I.S. 	: L mungkin kosong
  F.S.		: X ditambahkan sebagai elemen setelah Prec
  Proses 	: Melakukan alokasi sebuah elemen dan menambahkan elemen list
  			  setelah Prec yaitu
  			  jika alokasi berhasil, elemen setelah Prec yang baru bernilai X
  			  Jika alokasi gagal, maka I.S.= F.S. */
void InsVAfter (List *L, infotype X, infotype Xprec) {
    /*kamus lokal*/
    address P;
    address Prec;
    
    /*algoritma*/
    Prec = First(*L);
    while (info(Prec) != Xprec) {
        Prec = next(Prec);
    }
    
    P = Alokasi(X); 
    if(P != Nil){
        next(P) = next(Prec);
        next(Prec) = P;
    }   
}

/*mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last) {
    /*kamus lokal*/
    /*algoritma*/
    (*Last) = First(*L);
    (*Prec) = Nil;
    while(next(*Last)!=Nil) {
        (*Prec) = (*Last);
        (*Last) = next(*Last);
    }
}

/* Penghapusan ELemen */
/* I.S.		: List L tidak kosong
  F.S.		: Elemen pertama list dihapus den nilai info disimpan pada X
  			  dan alamat elemen pertama di-dealokasi */
void DelVFirst (List *L, infotype *X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    if(P!=Nil) {
        DelFirst(L, &P);
        (*X) = info(P);
        Dealokasi(&P);
    }
}

/* I.S.		: List L tidak kosong
  F.S.		: Elemen terakhir list dihapus : nilai info disimpan pada X
  			  dan alamat elemen terakhir di-dealokasi */
void DelVLast (List *L, infotype *X) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    DelLast(L, &P);
    (*X) = info(P);
    Dealokasi(&P);
}

/* I.S.		: List L tidak kosong
  F.S.		: Elemen list setelah Prec dihapus : nilai info disimpan pada X
  			  dan alamat elemen setelah Prec di-dealokasi */
void DelVAfter (List *L, infotype *X, infotype Xprec) {
    /*kamus lokal*/
    address P;
    address Prec;
    
    /*algoritma*/
    P = First(*L);
    if(info(First(*L)) == Xprec) {
        Prec = next(P);
        (*X) = info(Prec);
        next(P) = next(Prec);
        next(Prec) = Nil;
        Dealokasi(&Prec);
    } else {
        while(info(P) != Xprec) {
            P = next(P);
        }
        Prec = next(P);
        (*X) = info(next(P));
        next(P) = next(Prec);
        next(Prec) = Nil;
        Dealokasi(&Prec);
    }
}

/* Proses Semua Elemen List
{I.S.: List mungkin kosong}
{F.S.: Jika list tidak kosong, semua info yg disimpan pada elemen 
      list diprint. Jika list kosong, hanya menuliskan "list kosong"} */
void PrintInfo (List L) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    if(ListEmpty(L)) {
        printf("Moon maap list masih kosong..\n");
    } else {
        P = First(L);
        do {
            printf("%d | ", info(P));
            P = next(P);
        } while(P!=Nil);
        printf("\n");
    }
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L) {
    /*kamus lokal*/
    address P;
    int nb;
    
    /*algoritma*/
    nb = 0;
    P = First(L);
    while(P!=Nil) {
        nb++;
        P = next(P);
    } return nb;
}

#endif
     
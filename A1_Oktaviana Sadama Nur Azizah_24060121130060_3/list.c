/* Program   : list.c */
/* Deskripsi : file BODY modul list Circular */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 14 November 2022*/
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
    info(*P) = 0;
    next(*P) = Nil;
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertFirst (List *L, address P) {
    /*kamus lokal*/
    address Last;
    
    /*algoritma*/
    if(ListEmpty(*L)) {
        next(P) = First(*L); 
        First(*L) = P;
        next(P) = First(*L);
    } else {
        Last = First(*L);
        while (next(Last)!=First(*L)) {
            Last = next(Last); // mencari last
        }
        next(P) = First(*L);
        First(*L) = P;
        next(Last) = First(*L);
    }
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
    if(ListEmpty(*L)) {
        InsertFirst(L,P);
    } else {
        Last = First(*L);
        while (next(Last)!=First(*L)) {
            Last = next(Last);
        } InsertAfter(L,P,Last); // insert P pada List L setelah Last
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
    address Last;
    
    /*algoritma*/
    if(NbElmt(*L) == 1) {
        First(*L) = Nil;
    } else {
        (*P) = First(*L);
        Last = First(*L);
        while (next(Last)!=First(*L)) {
            Last = next(Last);
        }
        First(*L) = next(First(*L));
        next(Last) = First(*L);
        next(*P) = Nil; // karena P nya First(L) maka dihapus
    }
}

/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
void DelLast (List *L, address *P) {
    /*kamus lokal*/
    address Last, PrecLast;
    
    /*algoritma*/
    if(NbElmt(*L) == 1) {
        First(*L) = Nil;
    } else {
        Last = First(*L);
        PrecLast = Nil;
        while(next(Last)!=First(*L)) {
            PrecLast = Last;
            Last = next(Last);
        } 
        (*P) = Last;
        next(PrecLast) = First(*L);
        next(Last) = Nil;
    } 
}

/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */
void DelAfter (List *L, address *Pdel, address Prec) {
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
        InsertFirst(L,P);
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
    address P, Prec;
    
    /*algoritma*/
    Prec = First(*L);
    while (info(Prec) != Xprec) {
        Prec = next(Prec);
    } P = Alokasi(X); 
    if(P != Nil){
        InsertAfter(L,P,Prec);
    }   
}

/* Mencari alamat elemen terakhir dan sebelumnya*/
void AdrLast(List *L, address *Prec, address *Last) {
    /*kamus lokal*/
    /*algoritma*/
    (*Last) = First(*L);
    (*Prec) = Nil;
    while(next(*Last)!=First(*L)) {
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
    DelFirst(L,&P);
    (*X) = info(P);
    Dealokasi(&P);
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
    address P, Prec;
    
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
    P = First(L);
    if(!ListEmpty(L)) {
        do {
            printf("%d | ", info(P));
            P = next(P);
        }
        while (P!=First(L));
    } else {
        printf("[!List Kosong!]");
    } printf ("\n");
}

/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
int NbElmt (List L) {
    /*kamus lokal*/
    address P;
    int nb;
    
    /*algoritma*/
    P = First(L);
    nb = 1;
    while(next(P)!=First(L)) {
        nb++;
        P = next(P);
    } return nb;
}

/* Mencari apakah ada elemen list dengan info(P) = X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
address Search (List L, infotype X) {
    /*kamus lokal*/
    address P;
    boolean Found;
    
    /*algoritma*/
    P = First(L);
    Found = false;
    while(next(P)!=First(L) && !Found) {
        if (info(P) == X)  {
            Found = true;
        } else {
            P = next(P);
        }
    } return P;
}

/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
boolean FSearch (List L, address P) {
    /*kamus lokal*/
    address Psearch;
    boolean Found;
    
    /*algoritma*/
    Psearch = First(L);
    Found = false;
    while(Psearch!=First(L) && !Found) {
        if (Psearch == P)  {
            Found = true;
        } else {
            Psearch = next(Psearch);
        }
    } return Found;
}

/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P */
/* dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain*/
address SearchPrec (List L, infotype X) {
    /*kamus lokal*/
    address P, Prec;
    boolean Found;
    
    /*algoritma*/
    P = First(L);
    Prec = Nil;
    Found = false;
    do {
        if(info(P) == X) {
            Found = true;
        } else {
            Prec = P;
            P = next(P);
        }
    } while(P!=First(L) && !Found);
    return Prec;
}

/* Delete semua elemen list dan alamat elemen di-dealokasi */
void DelAll (List *L) {
    /*kamus lokal*/
    address P;
    
    /*algoritma*/
    do {
        DelFirst(L,&P);
        Dealokasi(&P);
        P = First(*L);
    } while(!ListEmpty(*L));
}

/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */
void InversList (List *L) {
    /*kamus lokal*/
    address Prec, Curr, P, Last;
    
    /*algoritma*/
    if(!ListEmpty(*L)) {
        Last = First(*L);
        while(next(Last) != First(*L)) {
            Last = next(Last); // mencari Last
        }
        Prec = Last;
        Curr = First(*L);
        do {
            P = next(Curr);
            next(Curr) = Prec;
            Prec = Curr;
            Curr = P;
        } while(Curr != First(*L));
        First(*L) = Prec;
    }
}

/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FInversList (List L) {
    /*kamus lokal*/
    List M;
    address P, Q;
    
    /*algoritma*/
    CreateList(&M);
    P = First(L);
    do {
        Q = Alokasi(info(P));
        if(Q!=Nil) {
            InsertFirst(&M,Q);
            P = next(P);
        } else {
            DelAll(&M);
            Q = Nil; // keluar while maka P dibuat Nil
        }
    } while(P!=First(L));
    return M;
}

/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */
void CopyList (List *L1, List *L2) {
    /*kamus lokal*/
    /*algoritma*/
    First(*L2) = First(*L1);
}

/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */
List FCopyList (List L) {
    /*kamus lokal*/
    List L2;
    address P, Q;
    
    /*algoritma*/
    CreateList(&L2);
    P = First(L);
    do {
        Q = Alokasi(info(P));
        if(Q!=Nil) {
            InsertLast(&L2,Q);
            P = next(P);
        } else {
            DelAll(&L2);
            Q = Nil;
        }
    } while(P!=First(L));
    return L2;
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 tetap, L3 adalah hasil konkatenasi L1 & L2 */
/* Jika semua alokasi berhasil, maka L3 adalah hasil konkatenasi*/
/* Jika ada alokasi yang gagal, semua elemen yang sudah dialokasi */
/* harus di-dealokasi dan L3=Nil*/
/* Konkatenasi dua buah list : L1 & L2 menghasilkan L3 yang “baru” */
/* Elemen L3 adalah hasil alokasi elemen yang “baru”. */
/* Jika ada alokasi yang gagal, maka L3 harus bernilai Nil*/
/* dan semua elemen yang pernah dialokasi didealokasi */
void Konkat (List L1, List L2, List *L3) {
    /*kamus lokal*/
    address P, Q;
    
    /*algoritma*/
    (*L3) = FCopyList(L1);
    P = First(L2);
    do {
        Q = Alokasi(info(P));
        if(Q!=Nil) {
            InsertLast(L3,Q);
            P = next(P);
        } else {
            DelAll(L3);
            Q = Nil;
        }
    } while(P!=First(L2));
}

/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2 */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2)*/
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
void Konkat1 (List *L1, List *L2, List *L3) {
    /*kamus lokal*/
    address LastL1, LastL2;
    
    /*algoritma*/
    CreateList(L3);
    LastL1 = First(*L1);
    LastL2 = First(*L2);
    if(!ListEmpty(*L1)) {
        // mencari Last dari L1
        while(next(LastL1)!=First(*L1)) {
            LastL1 = next(LastL1);
        } 
        // mencari Last dari L2
        while(next(LastL2)!=First(*L2)) {
            LastL2 = next(LastL2);
        }
        // concatenate
        next(LastL1) = First(*L2);
        next(LastL2) = First(*L1);
        // copy hasil concatenate ke list baru L3
        First(*L3) = First(*L1);
        // hasil akhir menghapus L1 dan L2
        First(*L1) = Nil;
        First(*L2) = Nil;
    } 
    // apabila L1 merupakan list kosong
    else {
        First(*L3) = First(*L2);
        First(*L2) = Nil;
    }
}

/* I.S. L mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah: untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah NbElmt(L) div 2 */
void PecahList (List *L1, List *L2, List L) {
    /*kamus lokal*/
    address P, Q;
    int i, N;
    
    /*algoritma*/
    CreateList(L1);
    CreateList(L2);
    i = 1;
    N = NbElmt(L)/2;
    P = First(L);
    do {
        Q = Alokasi(info(P));
        if(i<=N) {
            InsertLast(L1,Q);
            P = next(P);
            i++;
        } else {
            InsertLast(L2,Q);
            P = next(P);
            i++;
        }
    } while(P!=First(L)); 
}

#endif
     
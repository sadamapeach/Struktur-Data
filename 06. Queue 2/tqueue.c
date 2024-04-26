/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue1 */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 3 Oktober 2022*/
/***********************************/

#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"
#ifndef tqueue2_c

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/ 
void createQueue2(tqueue2 *Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/  
    (*Q).head = 0;
    (*Q).tail = 0;
    for(i=1; i<=5; i++) {
        (*Q).wadah[i] = '@';
    }
}

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    return Q.head;
}

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    return Q.tail;
}

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    return ((Q.head==0) && (Q.tail==0));
}

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    return ((Q.head==1) && (Q.tail==5));
}

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/ 
    if(!isEmptyQueue2(Q)) {
        return ((Q.head==1) && (Q.tail==1));
    }
}

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/  
    if(!isEmptyQueue2(Q)) {
        return Q.wadah[Q.head];
    } else {
        return '@';
    }
}

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/ 
    if(!isEmptyQueue2(Q)) {
        return Q.wadah[Q.tail];
    } else {
        return '@';
    }
}

/*function sizeQueue2(Q:tQueue2)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isEmptyQueue2(Q)) {
        return tail2(Q)-head2(Q)+1;
    } else {
        return 0;
    }
}

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/   
    for(i=1; i<=5; i++) {
        printf("%c ", Q.wadah[i]); 
    }
}

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    if(!isEmptyQueue2(Q)) { 
        for(i=Q.head; i<=Q.tail; i++) {
            printf("%c ", Q.wadah[i]);
        }
    } else {
        printf("Moon maap antrean kosong...");
    }
}

/*Function IsTailStop(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop(tqueue2 Q) {
    /*kamus lokal*/
    /*algoritma*/
    return ((Q.head!=1) && (Q.tail==5)); 
}

/*Procedure ResetHead(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead(tqueue2 *Q) {
    /*kamus lokal*/
    int i;
    int j;
    
    /*algoritma*/ 
    if(isTailStop(*Q) && (*Q).head>1) {
        j = 0;
        for(i=(*Q).head; i<=(*Q).tail; i++) {
            j++;
            (*Q).wadah[j] = (*Q).wadah[i];
            (*Q).wadah[i] = '@';
        } 
        (*Q).head = 1;
        (*Q).tail = j;
    } 
}

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isFullQueue2(*Q)) {
        if(isEmptyQueue2(*Q)) {
            (*Q).head = (*Q).head+1;
        }
        if(isTailStop(*Q)) {
            resetHead(Q);
        }
        (*Q).tail = (*Q).tail+1;
        (*Q).wadah[(*Q).tail] = E;
    }
}
  
/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, 
maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E) {
    /*kamus lokal*/
    /*algoritma*/
    if(isEmptyQueue2(*Q)) {
        (*E) = '@'; 
    } else {
        (*E) = (*Q).wadah[(*Q).head];
        (*Q).wadah[(*Q).head] = '@';
        (*Q).head = (*Q).head+1;
        if((*Q).head > (*Q).tail) {
            (*Q).head = 0;
            (*Q).tail = 0;
        }
    }
}

/*procedure enQueue2N( input/output Q:tQueue2, input N:integer )
{I.S.: Q terdefinisi, mungkin kosong, N <= kapasitas - panjang antrean}
{F.S.: elemen wadah Q bertambah <= N elemen bila belum penuh}
{proses: mengisi elemen dari keyboard, jika tail(Q) mencapai kapasitas, 
maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2N(tqueue2 *Q, int N) {
    /*kamus lokal*/
    int i,j;
    char x;
    
    /*algoritma*/
    if(isFullQueue2(*Q)) {
        printf("Moon maap antrean penuh..\n");
    } else {
        if(isEmptyQueue2(*Q)) {
            (*Q).head = 1;
        } 
        if(5-(*Q).tail < N) {
           j = 0; 
           for(i=(*Q).head; i<=(*Q).tail; i++) {
               j++;
               (*Q).wadah[j] = (*Q).wadah[i];
               (*Q).wadah[i] = '@';
           }
           (*Q).head = 1;
           (*Q).tail = j;
        }
        j = (*Q).tail+1;
        for(i=1; i<=N; i++) {
            printf("Masukkan elemen = ");
            scanf(" %c", &x);
            (*Q).wadah[j] = x;
            j++;
        }
        (*Q).tail = j-1;
    }
}

#endif

/* Program   : tqueue.c */
/* Deskripsi : file BODY modul queue1 */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 26 September 2022*/
/***********************************/

#include <stdio.h>
#include "tqueue1.h"
#include "boolean.h"
#ifndef tqueue1_c

/*procedure createQueue ( output Q:tQueue)
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dan elemen dengan '#' }*/ 
void createQueue(tqueue *Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    (*Q).head = 0;
    (*Q).tail = 0;
    for(i=1; i<=5; i++) {
        (*Q).wadah[i] = '#';
    }
}

/*function Head(Q:tQueue)-> integer 
{mengembalikan elemen terdepan antrian Q} */
int Head(tqueue Q) {
    /*kamus lokal*/
    /*algoritma*/
    return Q.head;
}

/*function Tail(Q:tQueue)-> integer 
{mengembalikan elemen terakhir antrian Q} */
int Tail(tqueue Q) {
    /*kamus lokal*/
    /*algoritma*/
    return Q.tail;
}

/*function isEmptyQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue(tqueue Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    return ((Q.head==0) && (Q.tail==0));
}
 
/*function isFullQueue(Q:tQueue) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue(tqueue Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    return ((Q.head==1) && (Q.tail==5));    
}

/*sedikit merubah urutan agar mudah diakses*/

/*function infoHead(Q:tQueue)-> character 
{mengembalikan nilai elemen terdepan antrian Q} */
/*pikirkan bila antrian kosong*/
char infoHead(tqueue Q) {
    if(!isEmptyQueue(Q)) {
        return Q.wadah[Q.head];
    } else {
        return '#';
    }
}

/*function infoTail(Q:tQueue)-> character 
{mengembalikan nilai elemen terakhir antrian Q} */
/*pikirkan bila antrian kosong*/
char infoTail(tqueue Q) {
    if(!isEmptyQueue(Q)) {
        return Q.wadah[Q.tail];
    } else {
        return '#';
    }    
}

/*function sizeQueue(Q:tQueue)-> integer 
{mengembalikan panjang antrian Q} */
int sizeQueue(tqueue Q) {
    /*kamus lokal*/
    /*algoritma*/
    return Q.tail;
}

/*procedure printQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua elemen wadah ke layar}*/
void printQueue(tqueue Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    for(i=1; i<=5; i++) {
        printf("%c ", Q.wadah[i]);
    }
}

/*procedure viewQueue(input Q:tQueue)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen Queue yang terisi, ke layar}*/
void viewQueue(tqueue Q) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    if(Q.head==1) {
        for(i=1; i<=Q.tail; i++) {
            printf("%c ", Q.wadah[i]);
        }
    } else {
        printf("Mianhae antrean kosong..");
    }
}

/*function isOneElement(Q:tQueue) -> boolean
{mengembalikan true jika hanya ada 1 elemen }*/
boolean isOneElement(tqueue Q) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isEmptyQueue(Q)) {
        return ((Q.head==1) && (Q.tail==1));
    }
}

/*procedure enqueue( input/output Q:tQueue, input E: character )
{I.S.: Q,E terdefinisi}
{F.S.: elemen wadah Q bertambah 1, bila belum penuh}
{proses: menambah elemen wadah Q } */
void enqueue(tqueue *Q, char E) {
    /*kamus lokal*/
    /*algoritma*/
    if(!isFullQueue(*Q)) {
        if(isEmptyQueue(*Q)) {
            (*Q).head++;
        } 
    (*Q).tail++;
    (*Q).wadah[(*Q).tail] = E;
    } else {
        printf("Please come back later, antrean penuh..");
    }
}
  
/*procedure deQueue( input/output Q:tQueue, output E: character )
{I.S.: Q terdefinisi}
{F.S.: E=infohead(Q) atau E='#' bila Q kosong, elemen wadah Q berkurang 1 }
{proses: mengurangi elemen wadah Q, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail menjadi 0 } */
void dequeue(tqueue *Q, char *E) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    if(isEmptyQueue(*Q)) {
        (*E) = '#';
    } else {
        (*E) = (*Q).wadah[(*Q).head];
        for(i=1; i<=Tail(*Q)-1; i++) {
            (*Q).wadah[i] = (*Q).wadah[i+1];
        }
        (*Q).wadah[(*Q).tail] = '#';
        (*Q).tail--;
    }
}

/*function longer(Q1:tqueue, Q2:tqueue) --> integer */
/*{mengembalikan ukuran yang terpanjang dari 2 antrian}*/
int longer(tqueue Q1, tqueue Q2) {
    /*kamus lokal*/
    /*algoritma*/
   if(Q1.tail > Q2.tail) {
       return Q1.tail;
   } else {
       return Q2.tail;
   }
}

/*procedure enqueueShort( input/output Q1:tQueue, input/output Q2:tQueue, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q1 atau Q2 bertambah 1, bila belum penuh}
{proses: menambah elemen wadah pada antrian terpendek (salah satu, Q1 atau Q2)} */
void enqueueShort(tqueue *Q1, tqueue *Q2, char E) {
    /*kamus lokal*/
    /*algoritma*/
    if((*Q1).tail < (*Q2).tail) {
        (*Q1).tail++;
        (*Q1).wadah[(*Q1).tail] = E;
    } else {
        (*Q2).tail++;
        (*Q2).wadah[(*Q2).tail] = E;
    }
}

/*procedure deQueueLong( input/output Q1:tQueue, input/output Q2:tQueue, output E: character )
{I.S.: }
{F.S.: E=infohead Q1 atau Q2, atau E='#' bila Q1 dan Q2 kosong, elemen wadah Q1 atau Q2 berkurang 1 }
{proses: mengurangi elemen wadah antrian terpanjang Q1 atau Q2, semua elemen di belakang head digeser maju }
{bila awalnya 1 elemen, maka Head dan Tail antrian menjadi 0 } */
/*diasumsikan apabila kedua queue memiliki panjang yang sama, maka Q1 deQueue*/
void dequeueLong(tqueue *Q1, tqueue *Q2, char *E) {
    /*kamus lokal*/
    int i;
    
    /*algoritma*/
    if((*Q1).tail >= (*Q2).tail) {
        (*E) = (*Q1).wadah[(*Q1).head];
        for(i=1; i<=Tail(*Q1)-1; i++) {
            (*Q1).wadah[i] = (*Q1).wadah[i+1];
        }
        (*Q1).wadah[(*Q1).tail] = '#';
        (*Q1).tail--;
    } else {
        (*E) = (*Q2).wadah[(*Q2).head];
        for(i=1; i<=Tail(*Q2)-1; i++) {
            (*Q2).wadah[i] = (*Q2).wadah[i+1];
        }
        (*Q2).wadah[(*Q2).tail] = '#';
        (*Q2).tail--;
    }
}

#endif

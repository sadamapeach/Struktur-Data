/* Program   : tstack.c */
/* Deskripsi : file BODY modul stack karakter */
/* NIM/Nama  : 24060121130060 / Oktaviana Sadama Nur Azizah*/
/* Tanggal   : 19 September 2022*/
/***********************************/

#include <stdio.h>
#include <math.h>
#include "tstack.h"
#include "boolean.h"
#ifndef tstack_c
// #define TSTACK_C

/* type Tstack = < wadah : array[1..10] of character,
                   top   : integer > */
// typedef	struct { char wadah[11];
//                  int  top; 
// 			   } Tstack;
/*karakter kosong dilambangkan dengan '#'  */
				 
/*procedure createStack( output T: Tstack)
	{I.S.: -}
	{F.S.: T terdefinisi, semua nilai elemen T.wadah = '#' }
	{Proses: menginisialisasi T} */
void createStack (Tstack *T) {
    /*kamus lokal*/
    int i;
    
    /*integer*/
    (*T).top = 0;
    for(i=1; i<=10; i++) {
        (*T).wadah[i] = '#';
    }
}

/*function top( T: Tstack) -> integer
	{mengembalikan posisi puncak stack } */
int top (Tstack T) {
    /*kamus lokal*/
    /*algoritma*/
    return T.top;
}

/*function infotop( T: Tstack) -> character
	{mengembalikan nilai elemen top stack } */
char infotop (Tstack T) {
    /*kamus lokal*/
    /*algoritma*/
    return T.wadah[T.top];
}

/*function isEmptyStack( T: Tstack) -> boolean
	{mengembalikan True jika T kosong } */
boolean isEmptyStack (Tstack T) {
    /*kamus lokal*/
    /*algoritma*/
    if (T.top == 0) {
        return true;
    } else {
        return false;
    }
}

/*function isFullStack( T: Tstack) -> boolean
	{mengembalikan True jika T penuh } */
boolean isFullStack (Tstack T) {
    /*kamus lokal*/
    /*algoritma*/
    if (T.top == 10) {
        return true;
    } else {
        return false;
    }
}

/*procedure push ( input/output T:Tstack, input E: character )
	{I.S.: T,E terdefinisi}
	{F.S.: infotop tetap, atau berisi nilai E }
	{Proses: mengisi elemen top baru, bila belum penuh }*/
void push (Tstack *T, char E) {
    /*kamus lokal*/
    /*algoritma*/
    if(isFullStack(*T) == false) {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    } else {
        printf("waduh, tabelnya udah penuh..\n");
    }
}

/*procedure pop ( input/output T:Tstack, output X: character )
	{I.S.: T terdefinisi}
	{F.S.: X= infotop stack lama, atau '#' }
	{Proses: mengambil elemen top, bila belum kosong }*/
void pop (Tstack *T, char *X) {
    /*kamus lokal*/
    /*algoritma*/
    if(isEmptyStack(*T) == false) {
        (*X) = (*T).wadah[(*T).top];
        (*T).wadah[(*T).top] = '#';
        (*T).top = (*T).top - 1;
    } else {
        (*X) = '#';
    }
}

/*procedure printStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan kondisi wadah T ke layar} 
	{setiap elemen dipisah tanda titik koma } */
void printStack (Tstack T) {
    /*kamus lokal*/
    int i; 
    
    /*algoritma*/ 
    for(i=1; i<=10; i++) {
       printf("%c, ", T.wadah[i]);
    }
}

/*procedure viewStack ( input T:Tstack )
	{I.S.: T terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen tak kosong T ke layar}  
	{setiap elemen dipisah tanda titik koma } */
void viewStack (Tstack T) {
    /*kamus lokal*/
    int i; 
    
    /*algoritma*/
    for(i=1; i<=T.top; i++) {
        printf("%c, ", T.wadah[i]);
    }
}

/*procedure pushN ( input/output T:Tstack, input N: integer )
	{I.S.: T,N terdefinisi}
	{F.S.: infotop tetap, atau top=N }
	{Proses: mengisi elemen top baru N kali, bila belum penuh }*/
void pushN (Tstack *T, int N) {
    /*kamus lokal*/
    int i;
    char x;
    
    /*algoritma*/
    for (i=(*T).top+1; i<=N+(*T).top; i++) {
        printf("Elemen ke-%d = ", i);
        scanf(" %c", &x);
        (*T).wadah[i] = x;
    }
    (*T).top = i-1;
}

/*procedure pushBabel1 ( input/output T:Tstack, input E: character )
	{I.S.: T terdefinisi, E terdefinisi }
	{F.S.: T bertambah 1 elemen (E) atau menjadi kosong bila penuh }
	{Proses: menumpuk top atau menghapus semua elemen }*/
void pushBabel1 (Tstack *T, char E) {
    /*kamus lokal*/
    
    /*algoritma*/
    if((*T).top >= 9) {
        createStack(T);
    } else {
        (*T).top++;
        (*T).wadah[(*T).top] = E;
    }
}

#endif
